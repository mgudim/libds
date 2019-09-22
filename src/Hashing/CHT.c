#include "Hashing/CHT.h"
#include "LinkedList/LL.h"
#include <stddef.h>


void chtC(
    CHT* self,
    LLNode* buckets,
    unsigned numBuckets,
    HashingFunction hashFn
) {
    for (unsigned i = 0; i < numBuckets; ++i) {
        buckets[i].next = NULL;
        buckets[i].data = NULL;
    }
    self->_buckets = buckets;
    self->_numBuckets = numBuckets;
    self->_hashFn = hashFn;
    return;
}


LLNode* chtFind(const CHT* self, int key) {
    unsigned index = (self->_hashFn)(key, self->_numBuckets);
    LLNode* curr = &(self->_buckets[index]);
    while (curr->next != NULL) {
        curr = curr->next;
        KVPair* currKV = (KVPair*) (curr->data);
        if (currKV->key == key) {
            return curr;
        }
    }
    return NULL;
}


void chtInsert(CHT* self, LLNode* kvPairNode) {
    int key = ((KVPair*) (kvPairNode->data))->key;
    unsigned index = (self->_hashFn)(key, self->_numBuckets);
    llInsertAfter(kvPairNode, &(self->_buckets[index]));
    return;
}


LLNode* chtRemove(CHT* self, int key) {
    unsigned index = (self->_hashFn)(key, self->_numBuckets);
    LLNode* prev = &(self->_buckets[index]);
    LLNode* curr = prev->next;
    LLNode* removedNode = NULL;
    while (curr != NULL) {
        KVPair* currKV = (KVPair*) (curr->data);
        if (currKV->key == key) {
            removedNode = curr;
            llUnlinkAfter(prev);
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    return removedNode;
}
