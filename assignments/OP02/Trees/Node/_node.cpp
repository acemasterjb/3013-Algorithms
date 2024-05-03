#include <algorithm>

#include "./_node.h"
#include "_node.h"

using std::max;

template <typename ValueType>
Node<ValueType>::Node(ValueType value) {
    this->_value = value;
    this->_left = nullptr;
    this->_right = nullptr;
    this->_parent = nullptr;
    this->_height = 1;
}

template<typename ValueType>
inline ValueType Node<ValueType>::value() {
    return this->_value;
}

template<typename ValueType>
inline Node<ValueType> * Node<ValueType>::left() {
    return this->_left;
}

template<typename ValueType>
inline Node<ValueType> * Node<ValueType>::right() {
    return this->_right;
}

template <typename ValueType>
inline Node<ValueType> *Node<ValueType>::parent() {
    return this->_parent;
}

template <typename ValueType>
inline unsigned int Node<ValueType>::height()
{
    return this->_height;
}

template <typename ValueType>
void Node<ValueType>::setParent(Node<ValueType> *newParent) {
    this->_parent = newParent;
}

template <typename ValueType>
inline void Node<ValueType>::setHeight(unsigned int newHeight) {
    this->_height = newHeight;
}

template<typename ValueType>
inline void Node<ValueType>::setLeft(Node<ValueType> * newLeft) {
    this->_left = newLeft;
    if (newLeft != nullptr)
        newLeft->_parent = this;
}

template<typename ValueType>
inline void Node<ValueType>::setRight(Node<ValueType> * newRight) {
    this->_right = newRight;
    if (newRight != nullptr)
        newRight->_parent = this;
}

template <typename ValueType>
Node<ValueType>::~Node() {
}
