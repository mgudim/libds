#include "LinkedList/DLL.h"


void dllInsertAfter(DLLNode* nodeToInsert, DLLNode* node) {
    nodeToInsert->prev = node;
    nodeToInsert->next = node->next;
    node->next = nodeToInsert;
    nodeToInsert->next->prev = nodeToInsert;
    return;
}


void dllUnlink(DLLNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    return;
}
