#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

#include "Node.h"

using std::string;
using std::cout;

template <typename ValueType>
class LinkedList {
    private:
        unsigned int _size;
        Node<ValueType> * _front;
        Node<ValueType> * _rear;

        void _initialize();
    protected:
        bool _isAscending;
        void sort();
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
        bool getOrder();

        // Setters
        void setAt(int location, ValueType newValue);
        void setFront(ValueType newValue);
        void setRear(ValueType newValue);
        void setOrder(bool isAscending);

        void pushAt(int location, ValueType value);
        void pushFront(ValueType value);
        void pushFront(LinkedList<ValueType> & other);
        void pushRear(ValueType value);
        void pushRear(LinkedList<ValueType> & other);

        // Mutators
        ValueType popAt(int location);
        ValueType popFront();
        ValueType popRear();

        ~LinkedList();
};

#endif