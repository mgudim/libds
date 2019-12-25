extern "C" {
    #include "BinaryTree/BST.h"
    #include "Utils/Utils.h"
    #include <limits.h>
}
#include "gtest/gtest.h"


static bool _isBinaryTreeRec(
    const BSTNode* node,
    void** prevKey,
    ComparisonFunction compareFn
) {
    if (node->leftChild != NULL) {
        bool res = _isBinaryTreeRec(node->leftChild, prevKey, compareFn);
        if (!res) {
            return false;
        }
    }
    void* thisKey = node->key;
    if (!compareFn(thisKey, *prevKey)) {
        return false;
    }
    *prevKey = node->key;
    if (node->rightChild != NULL) {
        bool res = _isBinaryTreeRec(node->rightChild, prevKey, compareFn);
        if (!res) {
            return false;
        }
    }
    return true;
}


static bool isBinaryTree(BST* bst) {
    if (bst->_root == NULL) {
        return true;
    }
    void* prevKey = (void*) INT_MIN;
    return _isBinaryTreeRec(bst->_root, &prevKey, bst->_compareFn);
}


#define INITIALIZE_BST\
    BST bst;\
    ComparisonFunction compareFn = &compareInts;\
    bstC(&bst, compareFn);


#define INITIALIZE_NODES(NUM)\
    BSTNode _nodes[NUM];\
    BSTNode* nodes[NUM + 1];\
    nodes[0] = NULL;\
    for (unsigned i = 1; i < NUM + 1; ++i) {\
        nodes[i] = &_nodes[i - 1];\
    }


#define MAKE_NODE(NUM, KEY, LEFT, RIGHT, PARENT)\
    nodes[NUM]->key = (void*) KEY;\
    nodes[NUM]->leftChild = nodes[LEFT];\
    nodes[NUM]->rightChild= nodes[RIGHT];\
    nodes[NUM]->parent= nodes[PARENT];\


TEST(IsBinaryTreeTest, _0) {
    INITIALIZE_BST;
    INITIALIZE_NODES(1);
    MAKE_NODE(1, 0, 0, 0, 0);
    bst._root = nodes[1];
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _1) {
    INITIALIZE_BST;
    INITIALIZE_NODES(2);
    MAKE_NODE(1, 1, 2, 0, 0);
    MAKE_NODE(2, 0, 0, 0, 1);
    bst._root = nodes[1];
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _2) {
    INITIALIZE_BST;
    INITIALIZE_NODES(2);
    MAKE_NODE(1, 0, 2, 0, 0);
    MAKE_NODE(2, 1, 0, 0, 1);
    bst._root = nodes[1];
    ASSERT_FALSE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _3) {
    INITIALIZE_BST;
    INITIALIZE_NODES(2);
    MAKE_NODE(1, 0, 0, 2, 0);
    MAKE_NODE(2, 1, 0, 0, 1);
    bst._root = nodes[1];
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _4) {
    INITIALIZE_BST;
    INITIALIZE_NODES(2);
    MAKE_NODE(1, 1, 0, 2, 0);
    MAKE_NODE(2, 0, 0, 0, 1);
    bst._root = nodes[1];
    ASSERT_FALSE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _5) {
    INITIALIZE_BST;
    INITIALIZE_NODES(3);
    MAKE_NODE(1, 1, 2, 3, 0);
    MAKE_NODE(2, 0, 0, 0, 1);
    MAKE_NODE(3, 2, 0, 0, 1);
    bst._root = nodes[1];
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _6) {
    INITIALIZE_BST;
    INITIALIZE_NODES(3);
    MAKE_NODE(1, 1, 2, 3, 0);
    MAKE_NODE(2, 2, 0, 0, 1);
    MAKE_NODE(3, 1, 0, 0, 1);
    bst._root = nodes[1];
    ASSERT_FALSE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _7) {
    INITIALIZE_BST;
    INITIALIZE_NODES(9);
    MAKE_NODE(1, 8, 2, 3, 0);
    MAKE_NODE(2, 3, 4, 5, 1);
    MAKE_NODE(3, 10, 0, 6, 1);
    MAKE_NODE(4, 1, 0, 0, 2);
    MAKE_NODE(5, 6, 7, 8, 2);
    MAKE_NODE(6, 14, 9, 0, 3);
    MAKE_NODE(7, 4, 0, 0, 5);
    MAKE_NODE(8, 7, 0, 0, 5);
    MAKE_NODE(9, 13, 0, 0, 6);
    bst._root = nodes[1];
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(IsBinaryTreeTest, _8) {
    INITIALIZE_BST;
    INITIALIZE_NODES(9);
    MAKE_NODE(1, 10, 2, 3, 0);
    MAKE_NODE(2, 5, 3, 4, 1);
    MAKE_NODE(3, 11, 5, 0, 1);
    MAKE_NODE(4, 3, 0, 0, 2);
    MAKE_NODE(5, 100, 0, 0, 2);
    bst._root = nodes[1];
    ASSERT_FALSE(isBinaryTree(&bst));
}


TEST(BST, _0) {
    INITIALIZE_BST;
    ASSERT_TRUE(bstFind(&bst, (void*) 1) == NULL);
}


TEST(BST, _1) {
    INITIALIZE_BST;
    BSTNode node;
    node.key = (void*) 1;
    bstInsert(&bst, &node);
    ASSERT_TRUE(isBinaryTree(&bst));
    ASSERT_TRUE(bstFind(&bst, (void*) 1) == &node);
}


TEST(BST, _2) {
    INITIALIZE_BST;
    BSTNode node1;
    node1.key = (void*) 1;
    bstInsert(&bst, &node1);
    BSTNode node2;
    node2.key = (void*) 2;
    bstInsert(&bst, &node2);
    ASSERT_TRUE(isBinaryTree(&bst));
    ASSERT_TRUE(bstFind(&bst, (void*) 1) == &node1);
    ASSERT_TRUE(bstFind(&bst, (void*) 2) == &node2);
}

TEST(BST, _3) {
    INITIALIZE_BST;
    BSTNode node2;
    node2.key = (void*) 2;
    bstInsert(&bst, &node2);
    BSTNode node1;
    node1.key = (void*) 1;
    bstInsert(&bst, &node1);
    ASSERT_TRUE(bstFind(&bst, (void*) 1) == &node1);
    ASSERT_TRUE(bstFind(&bst, (void*) 2) == &node2);
}


#define INITIALIZE_SMALL\
    INITIALIZE_BST;\
    unsigned const numNodes = 5;\
    BSTNode nodes[numNodes];\
    void* values[numNodes] = {\
        (void*) 3, (void*) 1, (void*) 2, (void*) 4, (void*) 0\
    };


TEST(BST, _4) {
    INITIALIZE_SMALL;
    for (unsigned i = 0; i < numNodes; ++i) {
        nodes[i].key = values[i];
        bstInsert(&bst, &nodes[i]);
    }
    for (unsigned i = 0; i < numNodes; ++i) {
        ASSERT_TRUE(bstFind(&bst, values[i]) == &(nodes[i]));
    }
}


TEST(BST, _5) {
    INITIALIZE_SMALL;
    for (unsigned i = 0; i < numNodes; ++i) {
        nodes[i].key = values[i];
        bstInsert(&bst, &nodes[i]);
    }
    ASSERT_TRUE(bstFindMinInSubtree(bst._root)->key == (void*) 0);
    ASSERT_TRUE(bstFindMaxInSubtree(bst._root)->key == (void*) 4);
}


TEST(BST, _6) {
    INITIALIZE_BST;
    BSTNode node;
    node.key = (void*) 0;
    bstInsert(&bst, &node);
    bstUnlink(&bst, &node);
    ASSERT_TRUE(bst._root == NULL);
}


TEST(BST, _7) {
    INITIALIZE_BST;
    BSTNode node0;
    node0.key = (void*) 0;
    bstInsert(&bst, &node0);
    BSTNode node1;
    node1.key = (void*) 1;
    bstInsert(&bst, &node1);
    bstUnlink(&bst, &node1);
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(BST, _8) {
    INITIALIZE_BST;
    BSTNode node1;
    node1.key = (void*) 1;
    bstInsert(&bst, &node1);
    BSTNode node0;
    node0.key = (void*) 0;
    bstInsert(&bst, &node0);
    bstUnlink(&bst, &node0);
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(BST, _9) {
    INITIALIZE_BST;
    BSTNode node3;
    node3.key = (void*) 3;
    bstInsert(&bst, &node3);
    BSTNode node1;
    node1.key = (void*) 1;
    bstInsert(&bst, &node1);
    BSTNode node4;
    node4.key = (void*) 4;
    bstInsert(&bst, &node4);
    bstUnlink(&bst, &node3);
    ASSERT_TRUE(isBinaryTree(&bst));
}


TEST(BST, _10) {
    for (unsigned j = 1; j < 10; ++j) {
        INITIALIZE_BST;
        INITIALIZE_NODES(9);
        MAKE_NODE(1, 8, 2, 3, 0);
        MAKE_NODE(2, 3, 4, 5, 1);
        MAKE_NODE(3, 10, 0, 6, 1);
        MAKE_NODE(4, 1, 0, 0, 2);
        MAKE_NODE(5, 6, 7, 8, 2);
        MAKE_NODE(6, 14, 9, 0, 3);
        MAKE_NODE(7, 4, 0, 0, 5);
        MAKE_NODE(8, 7, 0, 0, 5);
        MAKE_NODE(9, 13, 0, 0, 6);
        bst._root = nodes[1];
        bstUnlink(&bst, nodes[j]);
        ASSERT_TRUE(isBinaryTree(&bst));
    }
}

#undef MAKE_NODE
#undef INITIALIZE_NODES
#undef INITIALIZE_BST
#undef INITIALIZE_SMALL
