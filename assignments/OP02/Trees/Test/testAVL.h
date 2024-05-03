#ifndef TESTAVL_H

#include <chrono>

#include "./testBst.h"
#include "./testBst.cpp"

using namespace std;

#define TESTAVL_H

template <typename ValueType>
class TestAVLTree : public AVLTree<ValueType> {
    private:
        chrono::time_point<std::chrono::steady_clock> _timerStart;
        chrono::time_point<std::chrono::steady_clock> _timerEnd;
        int _opRuntime;
    public:
        TestAVLTree();
        TestAVLTree(ValueType rootValue);

        int operationRuntime();

        int heightOf(Node<ValueType> * node);
        int getBalanceFactor(Node<ValueType> * node);
        Node <ValueType> * search(ValueType value);

        void insert(ValueType value);
        void deleteBranch(Node<ValueType> * node);

        ~TestAVLTree();
};

#endif
