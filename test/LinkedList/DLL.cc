extern "C" {
    #include "LinkedList/DLL.h"
}
#include "gtest/gtest.h"


TEST(DLL, _0) {
    DLLNode head;
    DLLNode tail;
    head.prev = NULL;
    head.next = &tail;
    tail.next = NULL;
    tail.prev = &head;

    DLLNode node1;

    dllInsertAfter(&node1, &head);
    ASSERT_TRUE(head.prev == NULL);
    ASSERT_TRUE(head.next == &node1);
    ASSERT_TRUE(node1.prev == &head);
    ASSERT_TRUE(node1.next == &tail);
    ASSERT_TRUE(tail.prev == &node1);
    ASSERT_TRUE(tail.next == NULL);
}


TEST(DLL, _1) {
    DLLNode head;
    DLLNode tail;
    head.prev = NULL;
    head.next = &tail;
    tail.next = NULL;
    tail.prev = &head;

    DLLNode node1;

    dllInsertAfter(&node1, &head);
    dllUnlink(&node1);
    ASSERT_TRUE(head.prev == NULL);
    ASSERT_TRUE(head.next == &tail);
    ASSERT_TRUE(tail.prev == &head);
    ASSERT_TRUE(tail.next == NULL);
    ASSERT_TRUE(node1.prev == &head);
    ASSERT_TRUE(node1.next == &tail);
}
