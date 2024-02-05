#ifndef VECTOR_H
#define VECTOR_H

#include <fstream>
#include <string>

#include "containers/containers.h"
#include "containers/Node.cpp"
#include "string_manip.h"

using std::getline;
using std::string;

template <typename ElementType> class Vector : public LinkedList<ElementType> {
private:
public:
    Vector();
    Vector(bool isAscending);
    Vector(string filename, bool isAscending);
    Vector(Vector & other);
    Vector(ElementType * otherBegin, ElementType * otherEnd, bool isAscending);
    ~Vector();
};

template <typename ElementType>
inline Vector<ElementType>::Vector() : LinkedList<ElementType>() {}

template <typename ElementType>
Vector<ElementType>::Vector(bool isAscending) : LinkedList<ElementType>() {
    this->_isAscending = isAscending;
}

template <typename ElementType>
inline Vector<ElementType>::Vector(string filename, bool isAscending)
    : LinkedList<ElementType>() {
    this->_isAscending = isAscending;
    // assuming `input.dat` scenario
    std::ifstream fileStream(filename);
    int line;

    while (fileStream >> line)
        this->pushRear(line);
}

template <typename ElementType>
inline Vector<ElementType>::Vector(Vector & other) : LinkedList<ElementType>(other) {}

template <typename ElementType>
inline Vector<ElementType>::Vector(
    ElementType * otherBegin, ElementType * otherEnd, bool isAscending
) : LinkedList<ElementType>(otherBegin, otherEnd) {
        this->_isAscending = isAscending;
}

template <typename ElementType>
Vector<ElementType>::~Vector() {
}


#endif