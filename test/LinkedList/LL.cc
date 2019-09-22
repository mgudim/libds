extern "C" {
    #include "LinkedList/LL.h"
}
#include "gtest/gtest.h"


TEST(LL, _0) {
    LLNode head;
    head.data = (void*) 0;
    head.next = NULL;
    LLNode node1;
    node1.data = (void*) 1;

    llInsertAfter(&node1, &head);
    ASSERT_TRUE(head.next == &node1);
}


TEST(LL, _1) {
    LLNode head;
    head.data = (void*) 0;
    head.next = NULL;
    LLNode node1;
    node1.data = (void*) 1;

    llInsertAfter(&node1, &head);
    llUnlinkAfter(&head);
    ASSERT_TRUE(head.next == NULL);
    ASSERT_TRUE(node1.next == NULL);
}


TEST(LL, _2) {
    LLNode head;
    head.data = (void*) 0;
    head.next = NULL;
    LLNode node1;
    node1.data = (void*) 1;
    LLNode node2;
    node2.data = (void*) 2;

    llInsertAfter(&node1, &head);
    llInsertAfter(&node2, &node1);
    llUnlinkAfter(&head);
    ASSERT_TRUE(head.next == &node2);
    ASSERT_TRUE(node1.next == &node2);
}
