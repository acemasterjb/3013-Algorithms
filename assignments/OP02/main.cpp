#include <cassert>
#include <cmath>
#include <numeric>
#include <utility>
#include <vector>

#include "./Trees/trees.h"

using std::abs;
using std::accumulate;
using std::pair;
using std::vector;

template <typename ValueType>
void testTrees(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree);

template <typename ValueType>
bool testTreeBalance(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree);

template <typename ValueType>
bool testTreeHeight(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, int expectedHeightBalanced, int expectedHeightUnbalanced);

void postBenchmarks(pair<vector<int>, vector<int>> runtimes, string testSection = "");

int main() {

    TestAVLTree<int> avlTree;
    TestBinarySearchTree<int> bsTree;

    testTrees(avlTree, bsTree);
}

template <typename ValueType>
void testTrees(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree) {
    // last value is a duplicate, and will be ignored during insertion
    int values[] = {10, 20, 30, 40, 55, 68, 5, 15, 25, 35, 20};
    pair<vector<int>, vector<int>> runtimes = std::make_pair(vector<int> (), vector<int> ());
    for (int value : values) {
        avlTree.insert(value);
        runtimes.first.push_back(avlTree.operationRuntime());
        bsTree.insert(value);
        runtimes.second.push_back(bsTree.operationRuntime());
    }

    postBenchmarks(runtimes, "Insertion");

    runtimes = std::make_pair(vector<int> (), vector<int> ());

    assert(testTreeBalance(avlTree, bsTree));
    assert(testTreeHeight(avlTree, bsTree, 4, 6)); // including root

    int valuesToSearch[] = {5, 35, 68};
    for (int value : valuesToSearch) {
        avlTree.search(value);
        runtimes.first.push_back(avlTree.operationRuntime());
        bsTree.search(value);
        runtimes.second.push_back(bsTree.operationRuntime());
    }

    postBenchmarks(runtimes, "Searching");

    runtimes = std::make_pair(vector<int> (), vector<int> ());

    int valuesToDelete[] = {20, 35, 55};
    for (int value : valuesToDelete) {
        avlTree.deleteBranch(avlTree.search(value));
        runtimes.first.push_back(avlTree.operationRuntime());
        bsTree.deleteBranch(bsTree.search(value));
        runtimes.second.push_back(bsTree.operationRuntime());
    }

    postBenchmarks(runtimes, "Deletion");
}

template <typename ValueType>
bool testTreeBalance(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree) {
    int avlBalanceFactor = avlTree.getBalanceFactor(avlTree.root());
    int bstBalanceFactor = bsTree.getBalanceFactor(bsTree.root());
    return abs(avlBalanceFactor) < 2 && abs(bstBalanceFactor) > 2;
}

template <typename ValueType>
bool testTreeHeight(TestAVLTree<ValueType> &avlTree, TestBinarySearchTree<ValueType> &bsTree, int expectedHeightBalanced, int expectedHeightUnbalanced) {
    int treeHeightBalanced = avlTree.heightOf(avlTree.root());
    int treeHeightUnbalanced = bsTree.heightOf(bsTree.root());
    return treeHeightUnbalanced == expectedHeightUnbalanced && treeHeightBalanced == expectedHeightBalanced;
}

void postBenchmarks(pair<vector<int>, vector<int>> runtimes, string testSection) {
    float avgAVLTime = accumulate(runtimes.first.begin(), runtimes.first.end(), 0) / runtimes.first.size();
    float avgBSTTime = accumulate(runtimes.second.begin(), runtimes.second.end(), 0) / runtimes.second.size();

    cout << testSection << "\n---\nAVL Time: " << avgAVLTime << "ns\nBST Time: " << avgBSTTime << "ns\n\n";
}
