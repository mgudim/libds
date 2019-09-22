#include "LinkedList/DLL.h"


void dllInsertAfter(DLLNode* nodeToInsert, DLLNode* dllNode) {
    nodeToInsert->prev = dllNode;
    nodeToInsert->next = dllNode->next;
    dllNode->next = nodeToInsert;
    nodeToInsert->next->prev = nodeToInsert;
    return;
}


void dllUnlink(DLLNode* dllNode) {
    dllNode->prev->next = dllNode->next;
    dllNode->next->prev = dllNode->prev;
    return;
}
