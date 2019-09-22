extern "C" {
    #include "Hashing/CHT.h"
    #include "Hashing/HashingFunctions.h"
    #include "LinkedList/LL.h"
    #include <stddef.h>
    #include <stdint.h>
}
#include "gtest/gtest.h"


#define INITIALIZE_CHT\
    unsigned numBuckets = 10;\
    LLNode buckets[numBuckets];\
    HashingFunction hashFn = &getModPrime16;\
    CHT cht;\
    chtC(&cht, buckets, numBuckets, hashFn);

TEST(CHT, _0) {
    INITIALIZE_CHT;
    ASSERT_TRUE(chtFind(&cht, 1) == NULL);
}


TEST(CHT, _1) {
    INITIALIZE_CHT;
    KVPair kv;
    kv.key = 1;
    kv.value = (void*) 2;
    LLNode kvPairNode;
    kvPairNode.data = (void*) (&kv);

    chtInsert(&cht, &kvPairNode);
    LLNode* res = chtFind(&cht, 1);

    ASSERT_TRUE(res == &kvPairNode);
    KVPair* resKV = (KVPair*) (res->data);
    ASSERT_TRUE(resKV->key == 1);
    ASSERT_TRUE(resKV->value == (void*) 2);
}


TEST(CHT, _2) {
    INITIALIZE_CHT;
    LLNode* res = chtRemove(&cht, 1);
    ASSERT_TRUE(res == NULL);
}


TEST(CHT, _3) {
    INITIALIZE_CHT;
    KVPair kv;
    kv.key = 1;
    kv.value = (void*) 2;
    LLNode kvPairNode;
    kvPairNode.data = (void*) (&kv);
    chtInsert(&cht, &kvPairNode);

    LLNode* res = chtRemove(&cht, 1);
    ASSERT_TRUE(res == &kvPairNode);
    res = chtFind(&cht, 1);
    ASSERT_TRUE(res == NULL);
}


TEST(CHT, _4) {
    INITIALIZE_CHT;
    unsigned numElements = 20;
    KVPair kvs[numElements];
    for (unsigned i = 0; i < numElements; ++i) {
        kvs[i].key = i;
        kvs[i].value = (void*) (intptr_t) (100 + i);
    }
    LLNode kvPairNodes[numElements];
    for (unsigned i = 0; i < numElements; ++i) {
        kvPairNodes[i].data = (void*) (&kvs[i]);
        chtInsert(&cht, &kvPairNodes[i]);
    }

    for (unsigned i = 0; i < numElements; ++i) {
        LLNode* res = chtFind(&cht, i);
        ASSERT_TRUE(res == &kvPairNodes[i]);
        KVPair* resKV = (KVPair*) (res->data);
        ASSERT_TRUE (resKV == &kvs[i]);
        ASSERT_TRUE (resKV->key == kvs[i].key);
        ASSERT_TRUE (resKV->value == kvs[i].value);
        res = chtRemove(&cht, i);
        ASSERT_TRUE(res == &kvPairNodes[i]);
        res = chtFind(&cht, i);
        ASSERT_TRUE(res == NULL);
        res = chtRemove(&cht, i);
        ASSERT_TRUE(res == NULL);
    }
}
