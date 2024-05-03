#ifndef AVLTREE_H

#include "./_bst.h"
#include "./_bst.cpp"

#define AVLTREE_H


template <typename ValueType>
class AVLTree : public BinarySearchTree<ValueType> {
    private:
        Node<ValueType> * _rightRotate(Node<ValueType> * newNode);
        Node<ValueType> * _leftRotate(Node<ValueType> * newNode);
        Node<ValueType> * _insert(Node<ValueType> * node, ValueType value);

        Node<ValueType> * _deleteBranch(Node<ValueType> * node);

    public:
        AVLTree();
        AVLTree(ValueType rootValue);

        int heightOf(Node<ValueType> * node);
        int getBalanceFactor(Node<ValueType> * node);
        Node <ValueType> * search(ValueType value);

        void insert(ValueType value);
        void deleteBranch(Node<ValueType> * node);

        ~AVLTree();
};

#endif  // AVLTREE_H
