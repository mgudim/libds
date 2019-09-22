#include "Queue/QLL.h"


int qllIsEmpty(QLL* self) {
    return (self->head == self->back);
}


LLNode* qllPeekFront(QLL* self) {
    return self->head->next;
}


LLNode* qllPeekBack(QLL* self) {
    return self->back;
}


void qllPush(QLL* self, LLNode* node) {
    llInsertAfter(node, self->back);
    self->back = node;
    return;
}


LLNode* qllPop(QLL* self) {
    LLNode* front = self->head->next;
    llUnlinkAfter(self->head);
    return front;
}
