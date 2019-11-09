#include "DisjointSet/DSFW.h"


void dsfwMakeSet(DSFWNode* node) {
    node->parent = node;
    node->weight = 1;
    return;
}


DSFWNode* dsfwFind(DSFWNode* node) {
    DSFWNode* curr = node;
    while (curr->parent != curr) {
        curr = curr->parent;
    }
    return curr;
}


void dsfwUnion(DSFWNode* x, DSFWNode* y) {
    DSFWNode* xRoot = dsfwFind(x);
    DSFWNode* yRoot = dsfwFind(y);
    if (xRoot == yRoot) {
        return;
    }
    if (xRoot->weight > yRoot->weight) {
        yRoot->parent = xRoot;
        xRoot->weight += yRoot->weight;
    }
    else {
        xRoot->parent = yRoot;
        yRoot->weight += xRoot->weight;
    }
    return;
}
