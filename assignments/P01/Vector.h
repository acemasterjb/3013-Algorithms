#ifndef VECTOR_H
#define VECTOR_H

#include <string>

#include "containers/containers.h"

using std::string;

template <typename ElementType> class Vector : public LinkedList<ElementType> {
private:
public:
    Vector();
    Vector(bool isAscending);
    Vector(string filename, bool isAscending);
    Vector(const Vector & other, bool isAscending);
    Vector(const ElementType * other, bool isAscending);
    ~Vector();
};

template <typename ElementType> Vector<ElementType>::Vector(/* args */)
{
}

template <typename ElementType> Vector<ElementType>::~Vector()
{
}


#endif