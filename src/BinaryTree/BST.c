#include "BinaryTree/BST.h"
#include <stddef.h>
#include <stdio.h>


void bstC(BST* self, ComparisonFunction compareFn) {
    self->_root = NULL;
    self->_compareFn = compareFn;
    return;
}


static void _printTreeInOrder(const BSTNode* node, PrintFunction printFn) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }
    printf("node.key = ");
    printFn(node->key);
    printf(" node.data = ");
    printFn(node->data);
    BSTNode* leftChild = node->leftChild;
    if (leftChild == NULL) {
        printf(" leftChild = NULL");
    }
    else {
        printf(" leftChild.key = ");
        printFn(leftChild->key);
        printf(" leftChild.data = ");
        printFn(leftChild->data);
    }
    BSTNode* rightChild = node->rightChild;
    if (rightChild == NULL) {
        printf(" rightChild = NULL");
    }
    else {
        printf(" rightChild.key = ");
        printFn(rightChild->key);
        printf(" rightChild.data = ");
        printFn(rightChild->data);
    }
    printf("\n");
    _printTreeInOrder(node->leftChild, printFn);
    _printTreeInOrder(node->rightChild, printFn);
    return;
}


void bstPrint(const BST* self, PrintFunction printFn) {
    _printTreeInOrder(self->_root, printFn);
    return;
}


BSTNode* bstFind(const BST* self, void* key) {
    BSTNode* curr = self->_root;
    while (curr != NULL) {
        void* currKey = curr->key;
        if (currKey == key) {
            return curr;
        }
        else if (self->_compareFn(currKey, key)) {
            curr = curr->leftChild;
        }
        else {
            curr = curr->rightChild;
        }
    }
    return curr;
}


void bstInsert(BST* self, BSTNode* node) {
    node->parent = NULL;
    node->leftChild = NULL;
    node->rightChild= NULL;
    BSTNode* parent = self->_root;
    if (parent == NULL) {
        self->_root = node;
        return;
    }
    void* key = node->key;
    int isLeftChild = 0;
    while (1) {
        void* parentKey = parent->key;
        if (self->_compareFn(parentKey, key)) {
            isLeftChild = 1;
            BSTNode* leftChild = parent->leftChild;
            if (leftChild == NULL) {
                break;
            }
            parent = parent->leftChild;
        }
        else {
            isLeftChild = 0;
            BSTNode* rightChild = parent->rightChild;
            if (rightChild == NULL) {
                break;
            }
            parent = parent->rightChild;
        }
    }
    node->parent = parent;
    if (isLeftChild == 1) {
        parent->leftChild = node;
    }
    else {
        parent->rightChild = node;
    }
    return;
}


BSTNode* bstFindMinInSubtree(BSTNode* root) {
     BSTNode* minNode = root;
    while (minNode->leftChild != NULL) {
        minNode = minNode->leftChild;
    }
    return minNode;
}


BSTNode* bstFindMaxInSubtree(BSTNode* root) {
    BSTNode* maxNode = root;
    while (maxNode->rightChild != NULL) {
        maxNode = maxNode->rightChild;
    }
    return maxNode;
}


static void _replaceByRightChild(BST* self, BSTNode* node) {
    BSTNode* parent = node->parent;
    if (parent == NULL) {
        self->_root = node->rightChild;
        return;
    }
    BSTNode* rightChild = node->rightChild;
    if (node == parent->leftChild) {
        parent->leftChild = rightChild;
    }
    else {
        parent->rightChild = rightChild;
    }
    return;
}


static void _replaceByLeftChild(BST* self, BSTNode* node) {
    BSTNode* parent = node->parent;
    if (parent == NULL) {
        self->_root = node->leftChild;
        return;
    }
    BSTNode* leftChild = node->leftChild;
    if (node == parent->leftChild) {
        parent->leftChild = leftChild;
    }
    else {
        parent->rightChild = leftChild;
    }
    return;
}


void bstUnlink(BST* self, BSTNode* node) {
    if (node->leftChild == NULL) {
        _replaceByRightChild(self, node);
        return;
    }
    else if (node->rightChild == NULL) {
        _replaceByLeftChild(self, node);
    }
    else {
        BSTNode* rightMin = bstFindMinInSubtree(node->rightChild);
        if (rightMin == node->rightChild) {
            _replaceByRightChild(self, node);
            rightMin->leftChild = node->leftChild;
        }
        else {
            _replaceByRightChild(self, rightMin);
            rightMin->rightChild = node->rightChild;
            rightMin->leftChild = node->leftChild;
        }
        return;
    }
    return;
}
