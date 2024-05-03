#include "./_avlTree.h"

template <typename ValueType>
Node<ValueType> * AVLTree<ValueType>::_rightRotate(Node<ValueType> * subRoot) {
    Node<ValueType> * newRoot = subRoot->left();
    Node<ValueType> * newNodesLeft = newRoot->right();

    newRoot->setParent(subRoot->parent());
    newRoot->setRight(subRoot);
    subRoot->setLeft(newNodesLeft);
    
    if(newNodesLeft != nullptr)
        newNodesLeft->setParent(subRoot);

    subRoot->setHeight(
        max(
            heightOf(subRoot->left()),
            heightOf(subRoot->right())
        ) + 1
    );

    newRoot->setHeight(
        max(
            heightOf(newRoot->left()),
            heightOf(newRoot->right())
        ) + 1
    );

    return newRoot;
}

template <typename ValueType>
Node<ValueType> * AVLTree<ValueType>::_leftRotate(Node<ValueType> * subRoot) {
    Node<ValueType> * newRoot = subRoot->right();
    Node<ValueType> * newNodesRight = newRoot->left();

    newRoot->setParent(subRoot->parent());
    newRoot->setLeft(subRoot);
    subRoot->setRight(newNodesRight);

    if(newNodesRight != nullptr)
        newNodesRight->setParent(subRoot);

    newRoot->setHeight(
        max(
            heightOf(newRoot->left()),
            heightOf(newRoot->right())
        ) + 1
    );

    subRoot->setHeight(
        max(
            heightOf(subRoot->left()),
            heightOf(subRoot->right())
        ) + 1
    );

    return newRoot;
}

template <typename ValueType>
Node<ValueType> * AVLTree<ValueType>::_insert(Node<ValueType> * node, ValueType value) {
    node = BinarySearchTree<ValueType>::_insert(node, value);

    int nodeBalanceFactor = getBalanceFactor(node);

    if (nodeBalanceFactor > 1) {
        if (value < node->left()->value())
            return _rightRotate(node);
        else {
            node->setLeft(_leftRotate(node));
            return _rightRotate(node);
        }
    } else if (nodeBalanceFactor < -1) {
        if (value > node->right()->value())
            return _leftRotate(node);
        else {
            node->setRight(_rightRotate(node));
            return _leftRotate(node);
        }
    }

    // otherwise tree is already balanced; return
    return node;
}

template <typename ValueType>
Node<ValueType> * AVLTree<ValueType>::_deleteBranch(Node<ValueType> *node) {
    BinarySearchTree<ValueType>::_deleteBranch(node);

    int rootBalanceFactor = getBalanceFactor(this->_root);

    if (rootBalanceFactor > 1) {
        if (getBalanceFactor(this->_root->left()) > -1)
            return _rightRotate(this->_root);
        else {
            this->_root->setLeft(_leftRotate(this->_root));
            return _rightRotate(this->_root);
        }
    } else if (rootBalanceFactor < -1) {
        if (getBalanceFactor(this->_root->right()) < 1)
            return _leftRotate(this->_root);
        else {
            this->_root->setRight(_rightRotate(this->_root));
            return _leftRotate(this->_root);
        }
    }

    return this->_root;
}

template <typename ValueType>
AVLTree<ValueType>::AVLTree() : BinarySearchTree<ValueType>() {
}

template <typename ValueType>
AVLTree<ValueType>::AVLTree(ValueType rootValue) : BinarySearchTree<ValueType>(rootValue) {
}

template <typename ValueType>
int AVLTree<ValueType>::heightOf(Node<ValueType> * node) {
    if (node == nullptr)
        return 0;
    return node->height();
}

template <typename ValueType>
int AVLTree<ValueType>::getBalanceFactor(Node<ValueType> *node) {
    return BinarySearchTree<ValueType>::getBalanceFactor(node);
}

template <typename ValueType>
Node<ValueType> *AVLTree<ValueType>::search(ValueType value) {
    return BinarySearchTree<ValueType>::search(value);
}

template <typename ValueType>
void AVLTree<ValueType>::insert(ValueType value) {
    this->_root = this->_insert(this->_root, value);
}

template <typename ValueType>
void AVLTree<ValueType>::deleteBranch(Node<ValueType> *node) {
    if (node == nullptr)
        return;

    this->_root = _deleteBranch(node);
}
template <typename ValueType>
AVLTree<ValueType>::~AVLTree()
{
    while (this->_root != nullptr)
        this->_root = _deleteBranch(this->_root);
}
