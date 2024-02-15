#include "Node.h"

template <typename ValueType>
bool getOrder(Node<ValueType> * leftOperand, Node<ValueType> * rightOperand, bool isAscending) {
    if (!isAscending)
        return leftOperand->value() > rightOperand->value();
    return leftOperand->value() < rightOperand->value();    
}

template <typename ValueType>
Node<ValueType> * merge(
    Node<ValueType> * leftPartition, Node<ValueType> * rightPartition, bool isAscending
) {
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
void getPartitions(Node<ValueType> * input, Node<ValueType> ** leftPartition, Node<ValueType> ** rightPartition){
    Node<ValueType> * fast = input;
    Node<ValueType> * slow = input;
    Node<ValueType> * leftPartitionRear = nullptr;

    while (fast != nullptr && fast->next() != nullptr) {
        fast = fast->next()->next();
        leftPartitionRear = slow;
        slow = slow->next();
    }

    *leftPartition = input;
    *rightPartition = slow;
    if (leftPartitionRear != nullptr)
        leftPartitionRear->setNext(nullptr);
}

template <typename ValueType>
void mergeSort(Node<ValueType> ** front, bool isAscending) {
    if (*front == nullptr || (*front)->next() == nullptr)
        return;

    Node<ValueType> * leftPartitionFront;
    Node<ValueType> * rightPartitionFront;

    getPartitions(*front, &leftPartitionFront, &rightPartitionFront);

    mergeSort(&leftPartitionFront, isAscending);
    mergeSort(&rightPartitionFront, isAscending);

    *front = merge(leftPartitionFront, rightPartitionFront, isAscending);
}
