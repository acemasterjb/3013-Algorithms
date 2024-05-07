#include "./testAVL.h"
#include "testAVL.h"

template <typename ValueType>
TestAVLTree<ValueType>::TestAVLTree() : AVLTree<ValueType>() {
    this->_opRuntime = 0;
}

template <typename ValueType>
TestAVLTree<ValueType>::TestAVLTree(ValueType rootValue) : AVLTree<ValueType>(rootValue) {
}

template <typename ValueType>
int TestAVLTree<ValueType>::operationRuntime() {
    return this->_opRuntime;
}

template <typename ValueType>
Node<ValueType> *TestAVLTree<ValueType>::root() {
    return AVLTree<ValueType>::root();
}

template <typename ValueType>
int TestAVLTree<ValueType>::heightOf(Node<ValueType> *node)
{
    return AVLTree<ValueType>::heightOf(node);
}

template <typename ValueType>
int TestAVLTree<ValueType>::getBalanceFactor(Node<ValueType> *node) {
    return AVLTree<ValueType>::getBalanceFactor(node);
}

template <typename ValueType>
Node<ValueType> *TestAVLTree<ValueType>::search(ValueType value) {
    this->_timerStart = chrono::steady_clock::now();
    Node<ValueType> * result = AVLTree<ValueType>::search(value);
    this->_opRuntime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - this->_timerStart).count();
    return result;
}

template <typename ValueType>
void TestAVLTree<ValueType>::insert(ValueType value) {
    this->_timerStart = chrono::steady_clock::now();
    AVLTree<ValueType>::insert(value);
    this->_opRuntime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - this->_timerStart).count();
}

template <typename ValueType>
void TestAVLTree<ValueType>::deleteBranch(Node<ValueType> *node) {
    this->_timerStart = chrono::steady_clock::now();
    if (node != nullptr)
        AVLTree<ValueType>::deleteBranch(node);
    this->_opRuntime = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - this->_timerStart).count();
}

template <typename ValueType>
TestAVLTree<ValueType>::~TestAVLTree() {
}
