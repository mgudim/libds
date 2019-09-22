#include "Stack/SDLL.h"


int sdllIsEmpty(SDLL* self) {
    return (self->tail->prev == self->head);
}


DLLNode* sdllPeek(SDLL* self) {
    return self->tail->prev;
}


void sdllPush(SDLL* self, DLLNode* node) {
    dllInsertAfter(node, self->tail->prev);
    return;
}


DLLNode* sdllPop(SDLL* self) {
    DLLNode* top = self->tail->prev;
    dllUnlink(top);
    return top;
}
