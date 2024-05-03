#include <iostream>

#include "./_bst.h"

using std::cout;

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::_insert(Node<ValueType> * node, ValueType value) {
    if(node == nullptr)
                return new Node<ValueType>(value);

            if (value < node->value())
                node->setLeft(this->_insert(node->left(), value));
            else if (value > node->value())
                node->setRight(this->_insert(node->right(), value));

            node->setHeight(
                max(
                    heightOf(node->left()),
                    heightOf(node->right())
                ) + 1
            );

            return node;
}

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::_search(Node<ValueType> * currentNode, ValueType value) {
    // recursive approach taken since it's guaranteed to be cheap (AVL guarantees)
    if (currentNode == nullptr || currentNode->value() == value)
        return currentNode;

    if (currentNode->value() > value)
        return this->_search(currentNode->left(), value);
    else
        return this->_search(currentNode->right(), value);
}

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::_min(Node<ValueType> * node) {
    Node<ValueType> * currentNode = node;
    while (currentNode->left() != nullptr)
        currentNode = currentNode->left();
    
    return currentNode;
}

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::_max(Node<ValueType> * node) {
    Node<ValueType> * currentNode = node;
    while (currentNode->right() != nullptr)
        currentNode = currentNode->right();
    
    return currentNode;
}

template <typename ValueType>
void BinarySearchTree<ValueType>::_transplant(Node<ValueType> *nodeToEvict, Node<ValueType> *nodeToReplace) {
    if (nodeToEvict->parent() == nullptr)
        this->_root = nodeToReplace;
    else if (nodeToEvict == nodeToEvict->parent()->left())
        nodeToEvict->parent()->setLeft(nodeToReplace);
    else
        nodeToEvict->parent()->setRight(nodeToReplace);

    if (nodeToReplace != nullptr)
        nodeToReplace->setParent(nodeToEvict->parent());
    
}

template <typename ValueType>
void BinarySearchTree<ValueType>::_deleteBranch(Node<ValueType> *node) {
    if (node->left() == nullptr)
        this->_transplant(node, node->right());
    else if (node->right() == nullptr)
        this->_transplant(node, node->left());
    else {
        Node<ValueType> * successorNode = this->_min(node->right());

        if (successorNode != node->right())
            this->_transplant(successorNode, successorNode->right());

        this->_transplant(node, successorNode);
    }

    node->setHeight(
        max(
            heightOf(node->left()),
            heightOf(node->right())
        ) + 1
    );
}

template <typename ValueType>
BinarySearchTree<ValueType>::BinarySearchTree() {
    this->_root = nullptr;
}

template <typename ValueType>
BinarySearchTree<ValueType>::BinarySearchTree(ValueType rootValue) {
    this->_root = new Node<ValueType>(rootValue);
}

template <typename ValueType>
Node<ValueType> *BinarySearchTree<ValueType>::root() {
    return _root;
}

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::search(ValueType value) {
    return _search(_root, value);
}

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::successor(Node<ValueType> *node) {
    if (node->right() != nullptr)
        return this->_min(node->right());

    Node<ValueType> * currentNode = node;
    Node<ValueType> * parentNode = node->parent();
    while (parentNode != nullptr && currentNode == parentNode->right()) {
        currentNode = parentNode;
        parentNode = parentNode->parent();
    }

    return parentNode;    
}

template <typename ValueType>
Node<ValueType> * BinarySearchTree<ValueType>::predecessor(Node<ValueType> *node) {
    if (node->left() != nullptr)
        return this->_max(node->left());

    Node<ValueType> * currentNode = node;
    Node<ValueType> * parentNode = node->parent();
    while (parentNode != nullptr && currentNode == parentNode->left()) {
        currentNode = parentNode;
        parentNode = parentNode->parent();
    }

    return parentNode;    
}

template <typename ValueType>
int BinarySearchTree<ValueType>::heightOf(Node<ValueType> * node) {
    if (node == nullptr)
        return 0;
    return node->height();
}

template <typename ValueType>
int BinarySearchTree<ValueType>::getBalanceFactor(Node<ValueType> *node) {
    if (node == nullptr)
        return 0;
    return
        heightOf(node->left())
        - heightOf(node->right());
}

template <typename ValueType>
void BinarySearchTree<ValueType>::insert(ValueType value) {
    this->_root = _insert(_root, value);
}

template <typename ValueType>
void BinarySearchTree<ValueType>::deleteBranch(Node<ValueType> *node) {
    if (node == nullptr)
        return;
    
    _deleteBranch(node);
}

template <typename ValueType>
void BinarySearchTree<ValueType>::print()
{
    printFrom(_root);
}

template <typename ValueType>
void BinarySearchTree<ValueType>::printFrom(Node<ValueType> *node) {
    if (node == nullptr)
        return;
    
    printFrom(node->left());
    cout << node->value() << ", ";
    printFrom(node->right());
}

template <typename ValueType>
BinarySearchTree<ValueType>::~BinarySearchTree() {
    while (_root != nullptr)
        _deleteBranch(_root);
}