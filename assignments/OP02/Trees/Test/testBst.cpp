#include "./testBst.h"
// #include "testBst.h"

template <typename ValueType>
TestBinarySearchTree<ValueType>::TestBinarySearchTree() : BinarySearchTree<ValueType>() {
    this->_opRuntime = 0;
}

template <typename ValueType>
TestBinarySearchTree<ValueType>::TestBinarySearchTree(ValueType rootValue) : BinarySearchTree<ValueType>(rootValue) {
}

template <typename ValueType>
int TestBinarySearchTree<ValueType>::operationRuntime() {
    return this->_opRuntime;
}

template <typename ValueType>
int TestBinarySearchTree<ValueType>::heightOf(Node<ValueType> *node) {
    return BinarySearchTree<ValueType>::heightOf(node);
}

template <typename ValueType>
int TestBinarySearchTree<ValueType>::getBalanceFactor(Node<ValueType> *node) {
    return BinarySearchTree<ValueType>::getBalanceFactor(node);
}

template <typename ValueType>
Node<ValueType> *TestBinarySearchTree<ValueType>::search(ValueType value) {
    this->_timerStart = chrono::steady_clock::now();
    Node<ValueType> * result = BinarySearchTree<ValueType>::search(value);
    this->_opRuntime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - this->_timerStart).count();
    return result;
}

template <typename ValueType>
void TestBinarySearchTree<ValueType>::insert(ValueType value) {
    this->_timerStart = chrono::steady_clock::now();
    this->_root = BinarySearchTree<ValueType>::_insert(this->_root, value);
    this->_opRuntime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - this->_timerStart).count();
}

template <typename ValueType>
void TestBinarySearchTree<ValueType>::deleteBranch(Node<ValueType> *node) {
    this->_timerStart = chrono::steady_clock::now();
    if (node != nullptr)
        BinarySearchTree<ValueType>::_deleteBranch(node);
    this->_opRuntime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - this->_timerStart).count();
}

template <typename ValueType>
TestBinarySearchTree<ValueType>::~TestBinarySearchTree() {
}
