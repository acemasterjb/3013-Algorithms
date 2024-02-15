#include "LinkedList.h"
#include "sorting.h"

template <typename ValueType>
void LinkedList<ValueType>::_initialize() {
    this->_size = 0;
    this->_front = nullptr;
    this->_rear = this->_front;
    this->_isAscending = true;
}

template <typename ValueType>
void LinkedList<ValueType>::sort() {
    mergeSort(&this->_front, this->_isAscending);
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList() {
    _initialize();
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(LinkedList & other) {
    _initialize();

    Node<ValueType> * currentNode = other.front();
    while (currentNode != nullptr) {
        this->pushRear(currentNode->value());

        currentNode = currentNode->next();
    }
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(ValueType * otherBegin, ValueType * otherEnd) {
    _initialize();

    ValueType * currentValue = otherBegin;
    while (currentValue != otherEnd) {
        this->pushRear(*currentValue);

        currentValue++;
    }
}

template <typename ValueType>
LinkedList<ValueType>::LinkedList(ValueType initialValue) {
    _initialize();
    this->_size += 1;

    this->setFront(initialValue);
}

template <typename ValueType>
void LinkedList<ValueType>::print() {
    Node<ValueType> * currentNode = this->_front;

    cout << "\n[ ";
    while (currentNode != nullptr) {
        cout << currentNode->value() << ", ";

        currentNode = currentNode->next();
    }
    cout << ']';
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
    Node<ValueType> * currentNode = this->_front;
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
bool LinkedList<ValueType>::getOrder() {
    return this->_isAscending;
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

    Node<ValueType> * currentNode = this->_front;
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
void LinkedList<ValueType>::setOrder(bool isAscending) {
    this->_isAscending = isAscending;
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

    this->_size += 1;
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
    this->_size += 1;
    if (this->_front == nullptr) {
        this->_front = new Node<ValueType>(value);
        this->_front->setNext(this->_rear);
        return;
    }
    
    Node<ValueType> * prevNode = new Node<ValueType>(this->_front);
    this->_front = new Node<ValueType>(value);
    this->_front->setNext(prevNode);
}

template <typename ValueType>
void LinkedList<ValueType>::pushFront(LinkedList<ValueType> & other) {
    this->_size += other.size();
    Node<ValueType> * currentFront = new Node<ValueType>(this->_front);

    this->_front = new Node<ValueType>(other.front());
    Node<ValueType> * prevNode = this->_front;

    while (prevNode->next() != nullptr) {
        prevNode = prevNode->next();
    }

    prevNode->setNext(currentFront);
}

template <typename ValueType>
void LinkedList<ValueType>::pushRear(ValueType value) {
    if (this->_front == nullptr) {
        this->pushFront(value);
        return;
    }

    this->_size += 1;
    Node<ValueType> * newNode = new Node<ValueType>(value);
    Node<ValueType> * currentNode = this->_front;
    while (currentNode->next() != nullptr)
        currentNode = currentNode->next();

    currentNode->setNext(newNode);
    this->_rear = newNode; 
}

template <typename ValueType>
void LinkedList<ValueType>::pushRear(LinkedList<ValueType> & other) {
    this->_size += other.size();
    this->_rear->setNext(other.front());
    this->_rear = other.rear();
}

template <typename ValueType>
void LinkedList<ValueType>::inOrderPush(ValueType value) {
    this->pushRear(value);
    this->sort();
}

template <typename ValueType>
ValueType LinkedList<ValueType>::popAt(int location) {
    if (location == 0)
        return this->popFront();
    else if (location >= (_size - 1))
        return this->popRear();
    

    this->_size -= 1;
    Node<ValueType> * prevNode = this->_front;
    unsigned int index = 1;

    while (prevNode->next() != nullptr) {
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
    this->_size -= 1;
    Node<ValueType> * nodeToPop = this->_front;
    ValueType valueToReturn = nodeToPop->value();

    this->_front = this->_front->next();
    delete nodeToPop;
    return valueToReturn;
}

template <typename ValueType>
ValueType LinkedList<ValueType>::popRear() {
    this->_size -= 1;
    Node<ValueType> * prevNode = this->_front;

    while (prevNode->next() != nullptr)
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
    Node<ValueType> * nextNode = nullptr;
    while (currentNode->next() != nullptr) {
        nextNode = new Node<ValueType>(currentNode->next());
        delete currentNode;
        currentNode = nextNode;
    }
    delete currentNode;
}
