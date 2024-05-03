#ifndef NODE_H
#define NODE_H

template <typename ValueType>
class Node {
    private:
        ValueType _value;
        Node * _left;
        Node * _right;
        Node * _parent;
        unsigned int _height;

    public:
        Node(ValueType value);

        ValueType value();
        Node<ValueType> * left();
        Node<ValueType> * right();
        Node<ValueType> * parent();
        unsigned int height();

        void setRight(Node<ValueType> * newRight);
        void setLeft(Node<ValueType> * newLeft);
        void setParent(Node<ValueType> * newParent);
        void setHeight(unsigned int newHeight);

        ~Node();
};

#endif  // NODE_H
