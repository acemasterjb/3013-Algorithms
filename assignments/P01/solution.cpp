#include <algorithm>
#include <vector>

#include "Vector.h"

using std::vector;
using std::for_each;

Vector<int> * testFromEmptyVector();
Vector<int> * testFromArray();
void testPushMoreFromArray(Vector<int> * filledVector);
void testExtendVectorRear(Vector<int> * filledVector, Vector<int> * vectorToBeFilled);
void testPop(Vector<int> * filledVector, bool popFront);
void testPopAt(Vector<int> * filledVector);
void testFind(Vector<int> * filledVector);
Vector<int> * testCopy(Vector<int> * filledVector);
void testExtendVectorFront(Vector<int> * filledVector, Vector<int> * vectorToBeFilled);

int main(){
    Vector<int> * toBeFilledFromScratch = testFromEmptyVector();
    Vector<int> * toBeFilledFromArray = testFromArray();
    testPushMoreFromArray(toBeFilledFromArray);
    testExtendVectorRear(toBeFilledFromScratch, toBeFilledFromArray);
    testPop(toBeFilledFromScratch, true);
    testPop(toBeFilledFromScratch, false);
    testPopAt(toBeFilledFromArray);
    testFind(toBeFilledFromArray);
    testCopy(toBeFilledFromScratch);

    delete toBeFilledFromArray;
    delete toBeFilledFromScratch;
}

Vector<int> * testFromEmptyVector() {
    Vector<int> * toBeFilled = new Vector<int>();
    vector<int> filler = { 18, 20, 25, 18, 20, 25 };

    for (unsigned int i = 0; i < filler.size() / 2; i++)
        toBeFilled->pushFront(filler[i]);

    for (unsigned int i = (filler.size() / 2); i < filler.size(); i++)
        toBeFilled->pushRear(filler[i]);

    toBeFilled->print();
    return toBeFilled;
}

Vector<int> * testFromArray() {
    int filler[] = { 11, 25, 33, 47, 51 };
    Vector<int> * toBeInitialized = new Vector<int>(filler + 0, filler + 5, true);

    toBeInitialized->print();
    return toBeInitialized;
}

void testPushMoreFromArray(Vector<int> * filledVector) {
    filledVector->pushFront(9);
    filledVector->pushRear(63);

    filledVector->print();
}

void testExtendVectorRear(Vector<int> * filledVector, Vector<int> * vectorToBeFilled) {
    filledVector->pushRear(*vectorToBeFilled);    

    filledVector->print();
}

void testPop(Vector<int> * filledVector, bool popFront) {
    int x = 0;
    for (unsigned int i = 0; i < 3; i++) {
        if (popFront)
            x = filledVector->popFront();
        else
            x = filledVector->popRear();
    }

    filledVector->print();
    cout << '\n' << x;
}

void testPopAt(Vector<int> * filledVector) {
    int x = 0;
    x = filledVector->popAt(3);

    filledVector->print();
    cout << '\n' << x;
}

void testFind(Vector<int> *filledVector) {
    int x = 0;
    x = filledVector->find(51);
    cout << "\n`51` was found at: " << x;

    x = filledVector->find(99);
    cout
        << ((x > -1) ? "\n99 was found at " : "\n 99 is not in this Vector");
}

Vector<int> * testCopy(Vector<int> * filledVector) {
    Vector<int> copiedVector(*filledVector);
    copiedVector.print();

    return &copiedVector;
}

void testExtendVectorFront(Vector<int> * filledVector) {
    filledVector->pushFront(*filledVector); 

    filledVector->print();
}
