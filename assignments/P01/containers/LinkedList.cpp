#include "LinkedList.h"

template <typename ValueType>
void LinkedList<ValueType>::initialize() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = this->_front;
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList() {
    initialize();
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(LinkedList &other) {
    initialize();
    
    Node<ValueType> * currentNode = other.front();
    while (currentNode != nullptr) {
        this->_size++;
        this->pushRear(currentNode->value());

        currentNode = currentNode->next();
    }
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(ValueType *otherBegin, ValueType *otherEnd) {
    initialize();

    ValueType * currentValue = otherBegin;
    while (currentValue != otherEnd) {
        this->_size++;
        this->pushRear(*currentValue);
        
        currentValue++;
    }
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(ValueType initialValue) {
    initialize();

    this->setRear(initialValue);
}

template <typename ValueType>
void LinkedList<ValueType>::print() {
    Node<ValueType> * currentNode = this->front();

    cout << "[ " << '\n';
    while (currentNode != nullptr) {
        cout << currentNode->value() << ", ";

        currentNode = currentNode->next();
    }
    cout << "]\n";
}

template <typename ValueType>
unsigned int LinkedList<ValueType>::size() {
    return _size;
}

template <typename ValueType>
Node<ValueType> *LinkedList<ValueType>::front() {
    return _front;
}

template <typename ValueType>
Node<ValueType> *LinkedList<ValueType>::rear() {
    return _rear;
}

template <typename ValueType>
int LinkedList<ValueType>::find(ValueType value) {
    Node<ValueType> * currentNode = this->front();
    unsigned int index = 0;

    while (currentNode != nullptr) {
        if (value == currentNode->value())
            return index;

        index++;
        currentNode = currentNode->next();
    }
    return -1;
    
}

template <typename ValueType>
void LinkedList<ValueType>::setAt(int location, ValueType newValue) {
    if (location == 0){
        this->setFront(newValue);
        return;
    } else if (location >= (this->_size - 1)) {
        this->setRear(newValue);
        return;
    }

    Node<ValueType> * currentNode = this->front();
    unsigned int index = 1;

    while (currentNode != nullptr) {
        if (index++ == location) {
            currentNode->next()->setValue(newValue);
            return;
        }

        currentNode = currentNode->next();
    }
}

template <typename ValueType>
void LinkedList<ValueType>::setFront(ValueType value) {
    this->_front->setValue(value);
}

template <typename ValueType>
void LinkedList<ValueType>::setRear(ValueType value) {
    this->_rear->setValue(value);
}

template <typename ValueType>
void LinkedList<ValueType>::pushAt(int location, ValueType value) {
    if (location == 0){
        this->pushFront(value);
        return;
    } else if (location >= (this->_size - 1)) {
        this->pushRear(value);
        return;
    }

    Node<ValueType> * prevNode = this->_front;
    unsigned int index = 1;

    while (prevNode != nullptr) {
        if (index++ == location) {
            Node<ValueType> * newNode = new Node<ValueType>(value);
            Node<ValueType> * nextNode = prevNode->next();

            prevNode->setNext(newNode);
            newNode->setNext(nextNode);
            return;
        }

        prevNode = prevNode->next();
    }
}

template <typename ValueType>
void LinkedList<ValueType>::pushFront(ValueType value) {
    Node<ValueType> * prevNode = this->_front;
    Node<ValueType> * newNode = new Node<ValueType>(value);
    Node<ValueType> * nextNode = prevNode->next();

    prevNode->setNext(newNode);
    newNode->setNext(nextNode);
}

template <typename ValueType>
void LinkedList<ValueType>::pushRear(ValueType value) {
    Node<ValueType> * prevNode = this->_rear;
    Node<ValueType> * newNode = new Node<ValueType>(value);

    prevNode->setNext(newNode);
}

template <typename ValueType>
ValueType LinkedList<ValueType>::popAt(int location) {
    if (location == 0)
        return this->popFront();
    else if (location >= (_size - 1))
        return this->popRear();
    

    Node<ValueType> * prevNode = this->front();
    unsigned int index = 1;

    while (prevNode != nullptr) {
        if (index++ == location) {
                Node<ValueType> * nodeToPop = prevNode->next();
                ValueType valueToReturn = nodeToPop->value();
                Node<ValueType> * newNodeAtLocation = nodeToPop->next();

                prevNode->setNext(newNodeAtLocation);
                delete nodeToPop;
                return valueToReturn;
            };

        prevNode = prevNode->next();
    }    

    return ValueType();
}

template <typename ValueType>
ValueType LinkedList<ValueType>::popFront() {
    Node<ValueType> * nodeToPop = this->_front;
    ValueType valueToReturn = nodeToPop->value();

    this->_front = nodeToPop->next();
    delete nodeToPop;
    return valueToReturn;
}

template <typename ValueType>
ValueType LinkedList<ValueType>::popRear() {
    Node<ValueType> * prevNode = this->_front;

    while (prevNode->next() != this->_rear)
        prevNode = prevNode->next();

    ValueType valueToReturn = this->_rear->value();
    this->_rear = prevNode;
    delete prevNode->next();
    this->_rear->setNext(nullptr);

    return valueToReturn;
}

template <typename ValueType>
LinkedList<ValueType>::~LinkedList() {
    Node<ValueType> * currentNode = this->_front;
    for (unsigned int i = 0; i < _size; i++) {
        delete currentNode;
        currentNode = currentNode->next();
    }
}
