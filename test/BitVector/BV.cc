extern "C" {
    #include "BitVector/BV.h"
}
#include "gtest/gtest.h"


TEST(BV, _0) {
    int arr[3] = {0, 0, 0};
    ASSERT_EQ(getBit(arr, 0), 0);
    setBit(arr, 0);
    ASSERT_EQ(getBit(arr, 0), 1);
    ASSERT_EQ(getBit(arr, 95), 0);
    setBit(arr, 95);
    ASSERT_EQ(getBit(arr, 95), 1);
}
