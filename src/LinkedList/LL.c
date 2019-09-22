#include "LinkedList/LL.h"


void llInsertAfter(LLNode* nodeToInsert, LLNode* llNode) {
    nodeToInsert->next = llNode->next;
    llNode->next = nodeToInsert;
    return;
}


void llUnlinkAfter(LLNode* llNode) {
    llNode->next = llNode->next->next;
    return;
}
