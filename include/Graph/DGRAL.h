#ifndef DGRAL_INC
#define DGRAL_INC
#include "LinkedList/LL.h"


typedef struct DGRALNode {
    void* data;
    LLNode* succHead;
    LLNode* predHead;
} DGRALNode;


void dgralAddEdge(
    DGRALNode* from,
    DGRALNode* to,
    LLNode* pred,
    LLNode* succ
);
void dgralRemoveEdge(DGRALNode* from, DGRALNode* to);


#endif
