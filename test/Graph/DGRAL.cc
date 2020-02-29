extern "C" {
    #include "Graph/GraphUtils.h"
    #include "Graph/DGRAL.h"
    #include "LinkedList/LL.h"
}
#include "gtest/gtest.h"
#include <vector>
#include <set>


#define SET_UP(NUM_NODES, NUM_EDGES)\
    unsigned numNodes = NUM_NODES;\
    unsigned numEdges = NUM_EDGES;\
    DGRALNode nodes[numNodes];\
    LLNode succHeads[numNodes];\
    LLNode predHeads[numNodes];\
    LLNode llNodes[2 * numEdges];\
    DGRALNeighboursIterator iter;\
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
    unsigned tos[1] = {0};
    SET_UP(1, 1);

    dgralGetSuccessorsIterator(&nodes[0], &iter);
    ASSERT_EQ(dgralGetNextNeighbour(&iter), &nodes[0]);
    ASSERT_TRUE(dgralGetNextNeighbour(&iter) == NULL);
}


TEST(DGRAL, _1) {
    unsigned froms[1] = {0};
    unsigned tos[1] = {1};
    SET_UP(2, 1);

    dgralGetSuccessorsIterator(&nodes[0], &iter);
    ASSERT_EQ(dgralGetNextNeighbour(&iter), &nodes[1]);
    dgralGetPredecessorsIterator(&nodes[1], &iter);
    ASSERT_EQ(dgralGetNextNeighbour(&iter), &nodes[0]);
    dgralRemoveEdge(&nodes[0], &nodes[1]);
    ASSERT_TRUE(dgralGetNextNeighbour(&iter) == NULL);
    dgralGetPredecessorsIterator(&nodes[1], &iter);
    ASSERT_TRUE(dgralGetNextNeighbour(&iter) == NULL);
}


TEST(DGRAL, _2) {
    unsigned froms[6] = {0, 1, 0, 2, 2, 4};
    unsigned tos[6] = {1, 3, 2, 3, 4, 0};
    SET_UP(5, 6);

    std::vector<std::set<DGRALNode*>> expectedSuccs = {
        {&nodes[1], &nodes[2]},
        {&nodes[3]},
        {&nodes[3], &nodes[4]},
        {},
        {&nodes[0]}
    };
    std::vector<std::set<DGRALNode*>> expectedPreds = {
        {&nodes[4]},
        {&nodes[0]},
        {&nodes[0]},
        {&nodes[1], &nodes[2]},
        {&nodes[2]}
    };

    for (unsigned i = 0; i < 5; ++i) {
        std::set<DGRALNode*> succs;
        dgralGetSuccessorsIterator(&nodes[i], &iter);
        DGRALNode* nextNeighbour = dgralGetNextNeighbour(&iter);
        while (nextNeighbour != NULL) {
            succs.insert(nextNeighbour);
            nextNeighbour = dgralGetNextNeighbour(&iter);
        }
        ASSERT_EQ(succs, expectedSuccs[i]);
        std::set<DGRALNode*> preds;
        dgralGetPredecessorsIterator(&nodes[i], &iter);
        nextNeighbour = dgralGetNextNeighbour(&iter);
        while (nextNeighbour != NULL) {
            preds.insert(nextNeighbour);
            nextNeighbour = dgralGetNextNeighbour(&iter);
        }
        ASSERT_EQ(preds, expectedPreds[i]);
    }
}
