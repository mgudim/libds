#include "Heap/HSA.h"


void hsaC(
    HSA* self,
    void** arr,
    unsigned size,
    ComparisonFunction compareFn
) {
    self->_arr = arr;
    self->_size = size;
    self->_compareFn = compareFn;
    return;
}


void* hsaPeek(const HSA* self) {
    return self->_arr[1];
}


void hsaLower(HSA* self, unsigned index, void* newVal) {
    self->_arr[index] = newVal;
    unsigned currIdx = index;
    while (currIdx != 1) {
        void* currVal = self->_arr[currIdx];
        unsigned parentIdx = currIdx / 2;
        void* parentVal = self->_arr[parentIdx];
        if (self->_compareFn(currVal, parentVal)) {
            break;
        }
        else {
            self->_arr[parentIdx] = currVal;
            self->_arr[currIdx] = parentVal;
            currIdx = parentIdx;
        }
    }
    return;
}


void hsaRaise(HSA* self, unsigned index, void* newVal) {
    self->_arr[index] = newVal;
    unsigned currIdx = index;
    unsigned maxCurIdx = self->_size / 2;
    while (currIdx < maxCurIdx) {
        unsigned leftChildIdx = 2 * currIdx;
        unsigned rightChildIdx = leftChildIdx + 1;

        void* leftChildVal = self->_arr[leftChildIdx];
        unsigned minChildIdx = leftChildIdx;
        void* rightChildVal = self->_arr[rightChildIdx];
        if (self->_compareFn(leftChildVal, rightChildVal)) {
            minChildIdx = rightChildIdx;
        }
        void* currVal = self->_arr[currIdx];
        if (self->_compareFn(self->_arr[minChildIdx], currVal)) {
            break;
        }
        else {
            void* minChildVal = self->_arr[minChildIdx];
            self->_arr[minChildIdx] = currVal;
            self->_arr[currIdx] = minChildVal;
            currIdx = minChildIdx;
        }
    }
    return;
}
