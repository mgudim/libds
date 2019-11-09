extern "C" {
    #include "Queue/QLL.h"
}
#include "gtest/gtest.h"


#define INITIALIZE_QLL\
    QLL qll;\
    LLNode head;\
    qllC(&qll, &head);

TEST(QLL, _0) {
    INITIALIZE_QLL;
    ASSERT_TRUE((bool) qllIsEmpty(&qll));
}


TEST(QLL, _1) {
    INITIALIZE_QLL;
    LLNode node1;
    qllPush(&qll, &node1);
    ASSERT_TRUE(!(bool) qllIsEmpty(&qll));
    ASSERT_TRUE(qllPeekFront(&qll) == &node1);
    ASSERT_TRUE(qllPeekBack(&qll) == &node1);
}


TEST(QLL, _2) {
    INITIALIZE_QLL;
    LLNode node1;
    qllPush(&qll, &node1);
    LLNode node2;
    qllPush(&qll, &node2);
    ASSERT_TRUE(!(bool) qllIsEmpty(&qll));
    ASSERT_TRUE(qllPeekFront(&qll) == &node1);
    ASSERT_TRUE(qllPeekBack(&qll) == &node2);
}


TEST(QLL, _3) {
    INITIALIZE_QLL;
    LLNode node1;
    qllPush(&qll, &node1);
    LLNode node2;
    qllPush(&qll, &node2);
    LLNode* res = qllPop(&qll);
    ASSERT_TRUE(res == &node1);
    res = qllPop(&qll);
    ASSERT_TRUE(res == &node2);
}


#undef INITIALIZE_QLL
