#include "Node.h"

template <typename ValueType>
Node<ValueType>::Node(Node<ValueType> * other) {
    this->_value = other->value();
    *(this->_next) = *(other->next());
}

template <typename ValueType>
Node<ValueType>::Node(ValueType _value) {
    this->_value = _value;
    this->_next = nullptr;
}

template <typename ValueType>
ValueType Node<ValueType>::value() {
    return _value;
}

template <typename ValueType>
Node<ValueType> * Node<ValueType>::next() {
    return _next;
}

template <typename ValueType>
void Node<ValueType>::setValue(ValueType value) {
    this->_value = value;
}

template <typename ValueType>
void Node<ValueType>::setNext(Node<ValueType> * next) {
    this->_next = next;
}

template <typename ValueType>
Node<ValueType>::~Node() {
    delete _value;
    if (this->_next != nullptr)
        delete this->_next;    
}
