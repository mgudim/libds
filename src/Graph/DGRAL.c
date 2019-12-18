#include "Graph/DGRAL.h"
#include "LinkedList/LL.h"


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
