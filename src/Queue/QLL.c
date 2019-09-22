#include "Queue/QLL.h"
#include <stddef.h>


void qllC(QLL* self, LLNode* head) {
    head->next = NULL;
    self->_head = head;
    self->_back = head;
    return;
}


int qllIsEmpty(const QLL* self) {
    return (self->_head == self->_back);
}


LLNode* qllPeekFront(const QLL* self) {
    return self->_head->next;
}


LLNode* qllPeekBack(const QLL* self) {
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
