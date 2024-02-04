#ifndef NODE_H
#define NODE_H

template <typename ValueType> class Node {
private:
    ValueType _value;
    Node<ValueType> * _next;
public:
    Node(Node<ValueType> * other);
    Node(ValueType value);

    // Getters
    ValueType value();
    Node<ValueType> * next();

    // Setters
    void setValue(ValueType value);
    void setNext(Node<ValueType> * next);

    ~Node();
};


#endif