#include "LinkedList/LL.h"


void llInsertAfter(LLNode* nodeToInsert, LLNode* node) {
    nodeToInsert->next = node->next;
    node->next = nodeToInsert;
    return;
}


void llUnlinkAfter(LLNode* node) {
    node->next = node->next->next;
    return;
}
