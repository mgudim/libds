#include "Stack/SDLL.h"
#include <stddef.h>


void sdllC(SDLL* self, DLLNode* head, DLLNode* tail) {
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
    self->_head = head;
    self->_tail = tail;
    return;
}


int sdllIsEmpty(SDLL* self) {
    return (self->_tail->prev == self->_head);
}


DLLNode* sdllPeek(SDLL* self) {
    return self->_tail->prev;
}


void sdllPush(SDLL* self, DLLNode* node) {
    dllInsertAfter(node, self->_tail->prev);
    return;
}


DLLNode* sdllPop(SDLL* self) {
    DLLNode* top = self->_tail->prev;
    dllUnlink(top);
    return top;
}
