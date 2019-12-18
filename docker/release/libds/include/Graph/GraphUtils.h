#ifndef GRAPH_UTILS
#define GRAPH_UTILS
#include "Graph/DGRAL.h"
#include "LinkedList/LL.h"


void makeGraph(
    DGRALNode* nodes,
    LLNode* succHeads,
    LLNode* predHeads,
    unsigned numNodes, 
    unsigned* froms,
    unsigned* tos,
    unsigned numEdges,
    LLNode* llNodes
);

#endif
