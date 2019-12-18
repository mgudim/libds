extern "C" {
    #include "Graph/GraphUtils.h"
    #include "Graph/DGRAL.h"
    #include "LinkedList/LL.h"
}
#include "gtest/gtest.h"


#define SET_UP(NUM_NODES, NUM_EDGES)\
    unsigned numNodes = NUM_NODES;\
    unsigned numEdges = NUM_EDGES;\
    DGRALNode nodes[numNodes];\
    LLNode succHeads[numNodes];\
    LLNode predHeads[numNodes];\
    LLNode llNodes[2 * numEdges];\
    makeGraph(\
        nodes,\
        succHeads,\
        predHeads,\
        numNodes,\
        froms,\
        tos,\
        numEdges,\
        llNodes\
    )


TEST(DGRAL, _0) {
    unsigned froms[1] = {0};
    unsigned tos[1] = {1};
    SET_UP(2, 1);
    ASSERT_EQ((DGRALNode*)(nodes[0].succHead->next->data), &nodes[1]);
    ASSERT_EQ((DGRALNode*)(nodes[1].predHead->next->data), &nodes[0]);
    dgralRemoveEdge(&nodes[0], &nodes[1]);
    ASSERT_TRUE(nodes[0].succHead->next == NULL);
    ASSERT_TRUE(nodes[1].predHead->next == NULL);
}
