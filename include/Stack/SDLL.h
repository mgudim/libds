#ifndef SDLL_INC
#define SDLL_INC
#include "LinkedList/DLL.h"


typedef struct SDLL {
    DLLNode* head;
    DLLNode* tail;
} SDLL;;

int sdllIsEmpty(SDLL* self);
DLLNode* sdllPeek(SDLL* self);
void sdllPush(SDLL* self, DLLNode* node);
DLLNode* sdllPop(SDLL* self);


#endif
