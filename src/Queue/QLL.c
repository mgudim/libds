#include "Queue/QLL.h"


int qllIsEmpty(QLL* self) {
    return (self->_head == self->_back);
}


LLNode* qllPeekFront(QLL* self) {
    return self->_head->next;
}


LLNode* qllPeekBack(QLL* self) {
    return self->_back;
}


void qllPush(QLL* self, LLNode* node) {
    llInsertAfter(node, self->_back);
    self->_back = node;
    return;
}


LLNode* qllPop(QLL* self) {
    LLNode* front = self->_head->next;
    llUnlinkAfter(self->_head);
    return front;
}
