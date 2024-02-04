#include <cmath>

#include "Node.h"

using std::floor;

template <typename ValueType>
bool getOrder(Node<ValueType> * leftOperand, Node<ValueType> * rightOperand, bool isAscending) {
    if (isAscending)
        return leftOperand->value() > rightOperand->value();
    return leftOperand->value() < rightOperand->value();    
}

template <typename ValueType>
Node<ValueType> * merge(Node<ValueType> * leftPartition, Node<ValueType> * rightPartition, bool isAscending) {
    Node<ValueType> * frontOfSortedList = nullptr;

    if (leftPartition == nullptr)
        return rightPartition;
    else if (rightPartition == nullptr)
        return leftPartition;

    if (getOrder(leftPartition, rightPartition, isAscending)) {
        frontOfSortedList = leftPartition;
        frontOfSortedList->setNext(
            merge(frontOfSortedList->next(), rightPartition, isAscending)
        );
    } else {
        frontOfSortedList = rightPartition;
        frontOfSortedList->setNext(
            merge(frontOfSortedList->next(), leftPartition, isAscending)
        );
    }

    return frontOfSortedList;
}

template <typename ValueType>
Node<ValueType> * getRightPartition(Node<ValueType> * front, Node<ValueType> * rear) {
    Node<ValueType> * currentNode = front;
    Node<ValueType> * checkpoints = nullptr;
    float checkpointSize = 0.0;

    while (currentNode != rear->next()) {
        (checkpoints + checkpointSize++) = currentNode;
        currentNode = currentNode->next();
    }

    return (checkpoints + floor(checkpointSize / 2.0));
}

template <typename ValueType>
void mergeSort(Node<ValueType> * front, Node<ValueType> * rear, bool isAscending) {
    if (front == nullptr || front->next() == nullptr)
        return;

    Node<ValueType> * leftPartitionRear =  getRightPartition(front, rear);
    Node<ValueType> * rightPartitionFront = leftPartitionRear->next();

    mergeSort(front, leftPartitionRear, isAscending);
    mergeSort(rightPartitionFront, rear, isAscending);

    front = merge(front, rightPartitionFront, isAscending);
}
