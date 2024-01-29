#ifndef VECTOR_H
#define VECTOR_H

#include <string>

using std::string;

template <typename ElementType> class Vector
{
private:
    int size;
    int front;
    int rear;
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