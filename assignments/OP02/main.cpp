#include <cassert>
#include <ctime>
#include <cmath>
#include <numeric>
#include <utility>
#include <vector>

#include "./Trees/trees.h"

using std::abs;
using std::accumulate;
using std::pair;
using std::vector;
using uint = unsigned int;

struct TreeStats {
    int balanceFactor;
    int height;
};

vector<uint> generateTestInputs(int size, uint endRange);

template <typename ValueType>
void testTrees(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, vector<uint> testInput);

template <typename ValueType>
void testDelete(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, pair<vector<int>, vector<int>> &runtimes);

template <typename ValueType>
void testSearch(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, pair<vector<int>, vector<int>> &runtimes);

template <typename ValueType>
void testInsert(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, pair<vector<int>, vector<int>> &runtimes, vector<uint> testInputs);

template <typename ValueType>
pair<TreeStats, TreeStats> getTreeStats(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree);

void postBenchmarks(pair<vector<int>, vector<int>> runtimes, string testSection = "");

void postTreeStats(pair<TreeStats, TreeStats> treeStats);

int main() {

    // seed random generator
    std::srand(std::time(0));

    vector<uint> testInputs = generateTestInputs(10000, 50000);

    TestAVLTree<uint> avlTree;
    TestBinarySearchTree<uint> bsTree;

    testTrees(avlTree, bsTree, testInputs);
}

vector<uint> generateTestInputs(int size, uint endRange) {
    vector<uint> testInputs = vector<uint> ();
    for (int i = 0; i < size; i++)
        testInputs.push_back(std::rand() % endRange);    
    
    return testInputs;
}

template <typename ValueType>
void testTrees(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, vector<uint> testInput) {
    pair<vector<int>, vector<int>> runtimes;
    testInsert(avlTree, bsTree, runtimes, testInput);
    postBenchmarks(runtimes, "Insertion");

    runtimes = std::make_pair(vector<int> (), vector<int> ());
    testSearch(avlTree, bsTree, runtimes);
    postBenchmarks(runtimes, "Searching");

    pair<TreeStats, TreeStats> treeStats = getTreeStats(avlTree, bsTree);

    runtimes = std::make_pair(vector<int> (), vector<int> ());
    testDelete(avlTree, bsTree, runtimes);
    postBenchmarks(runtimes, "Deletion");

    postTreeStats(treeStats);
}

template <typename ValueType>
void testInsert(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, pair<vector<int>, vector<int>> &runtimes, vector<uint> testInputs)
{
    for (uint value : testInputs) {
        avlTree.insert(value);
        runtimes.first.push_back(avlTree.operationRuntime());
        bsTree.insert(value);
        runtimes.second.push_back(bsTree.operationRuntime());
    }
}

template <typename ValueType>
void testSearch(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, pair<vector<int>, vector<int>> &runtimes) {
    uint valuesToSearch[] = {5, 35, 68};
    for (uint value : valuesToSearch) {
        avlTree.search(value);
        runtimes.first.push_back(avlTree.operationRuntime());
        bsTree.search(value);
        runtimes.second.push_back(bsTree.operationRuntime());
    }
}

template <typename ValueType>
void testDelete(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, pair<vector<int>, vector<int>> &runtimes) {
    uint valuesToDelete[] = {20, 35, 55};
    for (uint value : valuesToDelete) {
        avlTree.deleteBranch(avlTree.search(value));
        runtimes.first.push_back(avlTree.operationRuntime());
        bsTree.deleteBranch(bsTree.search(value));
        runtimes.second.push_back(bsTree.operationRuntime());
    }
}

template <typename ValueType>
pair<TreeStats, TreeStats> getTreeStats(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree) {
    pair<TreeStats, TreeStats> treeStats;

    treeStats.first.balanceFactor = avlTree.getBalanceFactor(avlTree.root());
    treeStats.second.balanceFactor = bsTree.getBalanceFactor(bsTree.root());
    treeStats.first.height = avlTree.heightOf(avlTree.root());
    treeStats.second.height = bsTree.heightOf(bsTree.root());

    return treeStats;
}

void postBenchmarks(pair<vector<int>, vector<int>> runtimes, string testSection) {
    float avgAVLTime = accumulate(runtimes.first.begin(), runtimes.first.end(), 0)
        / runtimes.first.size();
    float avgBSTTime = accumulate(runtimes.second.begin(), runtimes.second.end(), 0)
        / runtimes.second.size();

    cout << testSection
         << "\n---\nAVL Time: " << avgAVLTime
         << "ns\nBST Time: " << avgBSTTime << "ns\n\n";
}

void postTreeStats(pair<TreeStats, TreeStats> treeStats) {
    cout << "\n\nTree Stats\n---\n";

    cout << "\nBalance Factors\n----\n"
         << "AVL Tree: " << treeStats.first.balanceFactor
         << "\nBS Tree: " << treeStats.second.balanceFactor;

    cout << "\n\nTree Heights\n----\n"
         << "AVL Tree: " << treeStats.first.height
         << "\nBS Tree: " << treeStats.second.height;
}
