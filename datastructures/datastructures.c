#include "datastructures.h"

#include <stddef.h>

voidList* createVoidList() {
    voidList *list = malloc(sizeof(voidList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void destroyVoidList(voidList *list) {
    while (list != NULL) {
        voidListNode *node = list->head;
        while (node != NULL) {
            voidListNode *next = node->next;
            free(node);
            node = next;
        }
    }
    free(list);
    list = NULL;
}

void appendVoidList(voidList *list, void *data) {
    voidListNode *node = malloc(sizeof(voidListNode));
    node->data = data;
    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

int sizeOfVoidList(voidList *list) {
    return list->size;
}
void *getVoidListHead(voidList *list) {
    return list->head->data;
}

void *getVoidListTail(voidList *list) {
    return list->tail->data;
}

void *getVoidListItem(voidList *list, int index) {
    int i = 0;
    voidListNode *node = list->head;
    while (i < index) {
        node = node->next;
        i = i + 1;
    }
    return node->data;
}

int isEmptyVoidList(voidList *list) {
    return list->size == 0;
}

int voidListContains(voidList *list, void *data) {
    voidListNode *node = list->head;
    for (int i = 0; i < list->size; ++i) {
        if (node->data == data) {
            return i;
        }
        node = node->next;
    }
    return -1;
}