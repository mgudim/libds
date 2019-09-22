#ifndef QLL_INC
#define QLL_INC
#include "LinkedList/LL.h"


typedef struct QLL {
    LLNode* _head;
    LLNode* _back;
} QLL;


int qllIsEmpty(QLL* self);
LLNode* qllPeekFront(QLL* self);
LLNode* qllPeekBack(QLL* self);
void qllPush(QLL* self, LLNode* node);
LLNode* qllPop(QLL* self);


#endif
