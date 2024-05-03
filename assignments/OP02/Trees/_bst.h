#ifndef AVLTREE_H
#define AVLTREE_H

#include "./Node/node.h"

template <typename ValueType>
class BinarySearchTree {
    private:

        Node<ValueType> * _search(Node<ValueType> * currentNode, ValueType value);
        Node<ValueType> * _min(Node<ValueType> * node);
        Node<ValueType> * _max(Node<ValueType> * node);

        void _transplant(Node<ValueType> * nodeToEvict, Node<ValueType> * nodeToReplace);
    protected:
        Node<ValueType> * _root;
        Node<ValueType> * _insert(Node<ValueType> * node, ValueType value);
        void _deleteBranch(Node<ValueType> * node);
    public:
        BinarySearchTree();
        BinarySearchTree(ValueType rootValue);

        Node<ValueType> * root();
        Node<ValueType> * search(ValueType value);
        Node<ValueType> * successor(Node<ValueType> * node);
        Node<ValueType> * predecessor(Node<ValueType> * node);
        int heightOf(Node<ValueType> * node);
        int getBalanceFactor(Node<ValueType> *node);

        void insert(ValueType value);
        void deleteBranch(Node<ValueType> * node);

        void print();
        void printFrom(Node<ValueType> * node);

        ~BinarySearchTree();
};

#endif  // AVLTREE_H
