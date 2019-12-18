#include "Graph/GraphUtils.h"
#include "Graph/DGRAL.h"
#include "LinkedList/LL.h"
#include <stddef.h>


void makeGraph(
    DGRALNode* nodes,
    LLNode* succHeads,
    LLNode* predHeads,
    unsigned numNodes, 
    unsigned* froms,
    unsigned* tos,
    unsigned numEdges,
    LLNode* llNodes
) {
    for (unsigned i = 0; i < numNodes; ++i) {
        succHeads[i].next = NULL;
        nodes[i].succHead = &succHeads[i];
        predHeads[i].next = NULL;
        nodes[i].predHead = &predHeads[i];
    }
    for (unsigned i = 0; i < numEdges; ++i) {
        unsigned idx = 2 * i;
        dgralAddEdge(&nodes[froms[i]], &nodes[tos[i]], &llNodes[idx], &llNodes[idx + 1]);
    }
    return;
}
