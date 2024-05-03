#ifndef TESTBST_H

#include <chrono>

#include "../_avlTree.h"
#include "../_avlTree.cpp"

using namespace std;

#define TESTBST_H

template <typename ValueType>
class TestBinarySearchTree : public BinarySearchTree<ValueType> {
    private:
        chrono::time_point<std::chrono::steady_clock> _timerStart;
        chrono::time_point<std::chrono::steady_clock> _timerEnd;
        int _opRuntime;
    public:
        TestBinarySearchTree();
        TestBinarySearchTree(ValueType rootValue);

        int operationRuntime();

        int heightOf(Node<ValueType> * node);
        int getBalanceFactor(Node<ValueType> * node);
        Node <ValueType> * search(ValueType value);

        void insert(ValueType value);
        void deleteBranch(Node<ValueType> * node);

        ~TestBinarySearchTree();
};

#endif  // TESTBST_H
