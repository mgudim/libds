#include "Graph/DGRAL.h"
#include "LinkedList/LL.h"
#include <stddef.h>


void dgralGetSuccessorsIterator(
    DGRALNode* node,
    DGRALNeighboursIterator* iter
) {
    iter->curr = node->succHead;
    return;
}


void dgralGetPredecessorsIterator(
    DGRALNode* node,
    DGRALNeighboursIterator* iter
) {
    iter->curr = node->predHead;
    return;
}


DGRALNode* dgralGetNextNeighbour(DGRALNeighboursIterator* iter) {
    iter->curr = iter->curr->next;
    DGRALNode* res = NULL;
    if (iter->curr != NULL) {
        res = (DGRALNode*) iter->curr->data;
    }
    return res;
}


void dgralAddEdge(
    DGRALNode* from,
    DGRALNode* to,
    LLNode* pred,
    LLNode* succ
) {
    succ->data = (void*) to;
    llInsertAfter(succ, from->succHead);
    pred->data = (void*) from;
    llInsertAfter(pred, to->predHead);
    return;
}


void dgralRemoveEdge(DGRALNode* from, DGRALNode* to) {
    LLNode* curr = from->succHead;
    while ((DGRALNode*) (curr->next->data) != to) {
        curr = curr->next;
    }
    llUnlinkAfter(curr);
    curr = to->predHead;
    while ((DGRALNode*) (curr->next->data) != from) {
        curr = curr->next;
    }
    llUnlinkAfter(curr);
    return;
}
