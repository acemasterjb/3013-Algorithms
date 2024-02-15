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
void testCopyAndExtend(Vector<int> * leftVector, Vector<int> * rightVector);
void testFromInput(Vector<int> * rightVector);
void testInOrderPush(Vector<int> * filledVector);

int main(){
    Vector<int> * filledFromScratch = testFromEmptyVector();
    Vector<int> * filledFromArray = testFromArray();
    testPushMoreFromArray(filledFromArray);
    testExtendVectorRear(filledFromScratch, filledFromArray);
    testPop(filledFromScratch, true);
    testPop(filledFromScratch, false);
    testPopAt(filledFromArray);
    testFind(filledFromArray);
    testCopyAndExtend(filledFromScratch, filledFromArray);
    testFromInput(filledFromScratch);
    testInOrderPush(filledFromArray);

    delete filledFromArray;
    delete filledFromScratch;
}

Vector<int> * testFromEmptyVector() {
    cout << "1️⃣. Fill Vector from the front and back";
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
    cout << "\n\n2️⃣. Fill Vector from an init'd array";
    int filler[] = { 11, 25, 33, 47, 51 };
    Vector<int> * toBeInitialized = new Vector<int>(filler + 0, filler + 5, true);

    toBeInitialized->print();
    return toBeInitialized;
}

void testPushMoreFromArray(Vector<int> * filledVector) {
    cout << "\n\n3️⃣. Push more stuff on a Vector, front and back";
    filledVector->pushFront(9);
    filledVector->pushRear(63);

    filledVector->print();
}

void testExtendVectorRear(Vector<int> * filledVector, Vector<int> * vectorToBeFilled) {
    cout << "\n\n4️⃣. Fill Vector from the front and back";
    filledVector->pushRear(*vectorToBeFilled);    

    filledVector->print();
}

void testPop(Vector<int> * filledVector, bool popFront) {
    cout << "\n\n5️⃣. Pop stuff from the front/back";
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
    cout << "\n\n7️⃣. Pop at a given location (3)";
    int x = 0;
    x = filledVector->popAt(3);

    filledVector->print();
    cout << '\n' << x;
}

void testFind(Vector<int> *filledVector) {
    cout << "\n\n8️⃣. Find an existing and non existing number";
    int x = 0;
    x = filledVector->find(51);
    cout << "\n`51` was found at: " << x;

    x = filledVector->find(99);
    cout
        << ((x > -1) ? "\n99 was found at " : "\n 99 is not in this Vector");
}

void testCopyAndExtend(Vector<int> * leftVector, Vector<int> * rightVector) {
    cout << "\n\n9️⃣. Fill Vector from the front and back";
    Vector<int> copiedVector(*leftVector);
    copiedVector.print();

    copiedVector.pushFront(*rightVector);
    copiedVector.print();
}

void testFromInput(Vector<int> * rightVector) {
    cout << "\n\n🔟. Fill Vector from an input file";
    string inputFileName = "input";
    Vector<int> filledFromInput(inputFileName, true);

    Vector<int> copiedVector(*rightVector);

    filledFromInput.pushRear(copiedVector);
    filledFromInput.print();
}

void testInOrderPush(Vector<int> * filledVector) {
    cout << "\n\n1️⃣1️⃣. Push an element in order";
    filledVector->inOrderPush(201);
    filledVector->inOrderPush(21);
    filledVector->print();
}
