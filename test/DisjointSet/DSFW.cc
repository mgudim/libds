extern "C" {
    #include "DisjointSet/DSFW.h"
}
#include "gtest/gtest.h"


TEST(DSFW, _0) {
    DSFWNode node;
    dsfwMakeSet(&node);
    ASSERT_TRUE(dsfwFind(&node) == &node);
    dsfwUnion(&node, &node);
    ASSERT_TRUE(dsfwFind(&node) == &node);
}


TEST(DSFW, _1) {
    DSFWNode node0;
    dsfwMakeSet(&node0);
    DSFWNode node1;
    dsfwMakeSet(&node1);
    ASSERT_TRUE(dsfwFind(&node0) == &node0);
    ASSERT_TRUE(dsfwFind(&node1) == &node1);
    dsfwUnion(&node0, &node1);
    ASSERT_TRUE(dsfwFind(&node0) == dsfwFind(&node1));
}


TEST(DSFW, _2) {
    const unsigned NUM_NODES = 5;
    DSFWNode nodes[NUM_NODES];
    for (unsigned i = 0; i < NUM_NODES; ++i) {
        dsfwMakeSet(&nodes[i]);
    }
    dsfwUnion(&nodes[0], &nodes[2]);
    dsfwUnion(&nodes[2], &nodes[4]);
    dsfwUnion(&nodes[1], &nodes[3]);

    DSFWNode* node0 = dsfwFind(&nodes[4]);
    ASSERT_TRUE(dsfwFind(&nodes[0]) == node0);
    ASSERT_TRUE(dsfwFind(&nodes[2]) == node0);
    DSFWNode* node1 = dsfwFind(&nodes[3]);
    ASSERT_TRUE(dsfwFind(&nodes[1]) == node1);
    ASSERT_TRUE(node0 != node1);
}
