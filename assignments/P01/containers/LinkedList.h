#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <iostream>
#include <string>

#include "Node.h"

using std::string;
using std::for_each;
using std::cout;

template <typename ValueType>
class LinkedList {
    private:
        unsigned int _size;
        Node<ValueType> * _front;
        Node<ValueType> * _rear;

        void initialize();
    public:
        LinkedList();
        LinkedList(LinkedList & other);
        LinkedList(ValueType * otherBegin, ValueType * otherEnd);
        LinkedList(ValueType initialValue);

        // Views
        void print();
        
        // Getters
        unsigned int size();
        Node<ValueType> * front();
        Node<ValueType> * rear();
        int find(ValueType value);

        // Setters
        void setAt(int location, ValueType newValue);
        void setFront(ValueType newValue);
        void setRear(ValueType newValue);

        void pushAt(int location, ValueType value);
        void pushFront(ValueType value);
        void pushRear(ValueType value);

        // Mutators
        ValueType popAt(int location);
        ValueType popFront();
        ValueType popRear();

        ~LinkedList();
};

#endif