#include <stdlib.h>

#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

typedef struct voidListNode {
    struct voidListNode *next;
    void *data;
} voidListNode;

typedef struct voidList {
    voidListNode *head;
    voidListNode *tail;
    size_t size;
} voidList;

voidList *createVoidList();
void destroyVoidList(voidList *list);
void appendVoidList(voidList *list, void *data);
int sizeOfVoidList(voidList *list);
void *getVoidListHead(voidList *list);
void *getVoidListTail(voidList *list);
void *getVoidListItem(voidList *list, int index);
int isEmptyVoidList(voidList *list);
int voidListContains(voidList *list, void *data);
void* voidListRemoveFromIndex(voidList *list, int index);
void* voidListRemoveItem(voidList *list, void *data);



#endif //DATASTRUCTURES_H
