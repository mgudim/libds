#ifndef HASHING_FUNCTIONS
#define HASHING_FUNCTIONS
#include <stddef.h>


size_t getModPrime16(int x, size_t numBuckets);
size_t multiplyShift(int x, unsigned a, unsigned char M);
unsigned char getPearsonHash256(const char key[], int size);


#endif
