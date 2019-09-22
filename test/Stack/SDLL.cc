extern "C" {
    #include "Stack/SDLL.h"
}
#include "gtest/gtest.h"


#define INITIALIZE_SDLL\
    DLLNode head;\
    DLLNode tail;\
    head.prev = NULL;\
    head.next = &tail;\
    tail.next = NULL;\
    tail.prev = &head;\
    SDLL sdll;\
    sdll.head = &head;\
    sdll.tail = &tail;\

TEST(SDLL, _0) {
    INITIALIZE_SDLL;
    ASSERT_TRUE((bool) sdllIsEmpty(&sdll));
}


TEST(SDLL, _1) {
    INITIALIZE_SDLL;

    DLLNode node1;
    sdllPush(&sdll, &node1);
    ASSERT_TRUE(!(bool) sdllIsEmpty(&sdll));
    ASSERT_TRUE(sdllPeek(&sdll) == &node1);
}


TEST(SDLL, _2) {
    INITIALIZE_SDLL;

    DLLNode node1;
    sdllPush(&sdll, &node1);
    sdllPop(&sdll);
    ASSERT_TRUE((bool) sdllIsEmpty(&sdll));
}

#undef INITIALIZE_SDLL
