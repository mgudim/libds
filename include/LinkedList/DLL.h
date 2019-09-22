#ifndef DLL_INC
#define DLL_INC


typedef struct DLLNode {
    void* data;
    struct DLLNode* next;
    struct DLLNode* prev;
} DLLNode;


void dllInsertAfter(DLLNode* nodeToInsert, DLLNode* dllNode);
void dllUnlink(DLLNode* dllNode);


#endif
