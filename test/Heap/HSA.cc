extern "C" {
    #include "Heap/HSA.h"
    #include "Utils/Utils.h"
    #include <stdint.h>
}
#include "gtest/gtest.h"


#define INITIALIZE_HSA\
    unsigned const size = 7;\
    void* arr[size + 1];\
    ComparisonFunction compareFn = &compareInts;\
    HSA hsa;\
    hsaC(&hsa, arr, size, compareFn);

TEST(HSA, _0) {
    INITIALIZE_HSA;
    arr[1] = (void*) 1;
    ASSERT_TRUE(hsaPeek(&hsa) == (void*) 1);
}


TEST(HSA, _1) {
    INITIALIZE_HSA;
    for (unsigned i = 1; i < size + 1; ++i) {
        arr[i] = (void*) (intptr_t) i;
    }
    hsaLower(&hsa, 6, (void*) 0);
    void* expected[size] = {
        (void*) 0,
        (void*) 2,
        (void*) 1,
        (void*) 4,
        (void*) 5,
        (void*) 3,
        (void*) 7
    };
    for (unsigned i = 0; i < size; ++i) {
        ASSERT_TRUE(arr[i + 1] == expected[i]);
    }
}


TEST(HSA, _2) {
    INITIALIZE_HSA;
    arr[1] = (void*) 1;
    arr[2] = (void*) 2;
    arr[3] = (void*) 3;
    arr[4] = (void*) 5;
    arr[5] = (void*) 4;
    arr[6] = (void*) 6;
    arr[7] = (void*) 7;
    hsaRaise(&hsa, 1, (void*) 8);
    void* expected[size] = {
        (void*) 2,
        (void*) 4,
        (void*) 3,
        (void*) 5,
        (void*) 8,
        (void*) 6,
        (void*) 7
    };
    for (unsigned i = 0; i < size; ++i) {
        ASSERT_TRUE(arr[i + 1] == expected[i]);
    }
}


#undef INITIALIZE_HSA
