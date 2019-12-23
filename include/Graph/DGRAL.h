#ifndef DGRAL_INC
#define DGRAL_INC
#include "LinkedList/LL.h"


typedef struct DGRALNode {
    void* data;
    LLNode* succHead;
    LLNode* predHead;
} DGRALNode;
typedef struct DGRALNeighboursIterator {
    LLNode* curr;
} DGRALNeighboursIterator;


void dgralGetSuccessorsIterator(
    DGRALNode* node,
    DGRALNeighboursIterator* iter
);
void dgralGetPredecessorsIterator(
    DGRALNode* node,
    DGRALNeighboursIterator* iter
);
DGRALNode* dgralGetNextNeighbour(DGRALNeighboursIterator* iter);
void dgralAddEdge(
    DGRALNode* from,
    DGRALNode* to,
    LLNode* pred,
    LLNode* succ
);
void dgralRemoveEdge(DGRALNode* from, DGRALNode* to);


#endif
