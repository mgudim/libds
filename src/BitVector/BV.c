#include "BitVector/BV.h"


static const unsigned _W = sizeof(int) * 8;

int getBit(const int* arr, unsigned i) {
    return (int) ((arr[i / _W] & (1 << (i % _W))) != 0);
}


void setBit(int* arr, unsigned i) {
    arr[i / _W] |= (1 << (i % _W));
    return;
}


void clearBit(int* arr, unsigned i) {
    arr[i / _W] &= (~(1 << (i % _W)));
    return;
}


void negateBit(int* arr, unsigned i) {
    arr[i / _W] ^= (1 << (i % _W));
    return;
}
