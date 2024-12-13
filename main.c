#include <assert.h>
#include <stdio.h>
#include "datastructures/datastructures.h"
#include "compare/compare.h"

int main(void) {
    // Integers
    voidList *intList = createVoidList();
    int a = 132;
    int *int_p = &a;
    appendVoidList(intList, int_p);
    assert(("a was not made head\n", 132 == * (int *) getVoidListHead(intList)));
    assert(("a was not made tail\n", 132 == * (int *) getVoidListTail(intList)));
    int b = -13;
    int_p = &b;
    appendVoidList(intList, int_p);
    assert(("Head changed, when tail was changed\n", a == *(int *) getVoidListHead(intList)));
    assert(("b was not made tail", b == * (int *) getVoidListTail(intList)));
    int c = 314159;
    int_p = &c;
    appendVoidList(intList, int_p);
    assert(("c was not made tail", c == * (int *) getVoidListTail(intList)));

    int x = 314159;
    int* int_p2 = &x;
 //   printf("Intcompare: %d\n", int_compare(((void*) int_p2), ((void *) int_p)));
    printf(("%d is at Index %d in intList\n"), x, voidListContains(intList, int_p));
    int_p = &x;
    printf(("%d is at Index %d in intList\n"), x, voidListContains(intList, int_p));

    printf("Current size of intList: %d\n", sizeOfVoidList(intList));
    printf("Head value at the beginning of intList: %d\n", *(int *) getVoidListHead(intList));
    printf("Tail value at the end of intList: %d\n", *(int *) getVoidListTail(intList));
    for (int i = 0; i < sizeOfVoidList(intList); i++) {
        printf("Element at index %d: %d\n", i, *(int *) getVoidListItem(intList, i));
    }

    // Floats
    voidList *floatList = createVoidList();
    double pi = 3.14159265359;
    double *float_p = &pi;
    appendVoidList(floatList, float_p);
    printf("Current size of floatList: %d\n", sizeOfVoidList(floatList));
    for (int i = 0; i < sizeOfVoidList(floatList); i++) {
        printf("Element at index %d: %f\n", i, *(double *) getVoidListItem(floatList, i));
    }

    // Strings
    voidList *stringList = createVoidList();
    char *string = "Hello World!";
    char **string_p = &string;
    appendVoidList(stringList, string_p);
    assert(("string was not made head\n", string == *(char **) getVoidListHead(stringList)));
    assert(("string was not made tail\n", string == *(char **) getVoidListTail(stringList)));
    char *string2 = "How YOU doin' ? ;)";
    string_p = &string2;
    appendVoidList(stringList, string_p);
    assert(("string2 was not made tail\n", string2 == *(char **) getVoidListTail(stringList)));
    char * string3 = "Bye World!";
    string_p = &string3;
    appendVoidList(stringList, string_p);
    assert(("string3 was not made tail\n", string3 == *(char **) getVoidListTail(stringList)));
    printf("Current size of stringList: %d\n", sizeOfVoidList(stringList));
    printf("Head value at the beginning of stringList: %s\n", *(char **) getVoidListHead(stringList));
    printf("Tail value at the end of stringList: %s\n", *(char **) getVoidListTail(stringList));

    for (int i = 0; i < sizeOfVoidList(stringList); i++) {
        printf("Element at index %d: %s\n", i, *(char **) getVoidListItem(stringList, i));
    }

    // voidList of voidLists
    voidList *motherOfAllVoidLists = createVoidList();
    appendVoidList(motherOfAllVoidLists, intList);
    appendVoidList(motherOfAllVoidLists, floatList);
    appendVoidList(motherOfAllVoidLists, stringList);
    printf("Current size of motherOfAllVoidLists: %d\n", sizeOfVoidList(motherOfAllVoidLists));

    printf("first int: %d\n", *(int*) getVoidListHead(getVoidListHead(motherOfAllVoidLists)));
    printf("last int: %d\n", *(int*) getVoidListTail(getVoidListHead(motherOfAllVoidLists)));
    printf("first String: %s\n", *(char**) getVoidListHead(getVoidListTail(motherOfAllVoidLists)));
    printf("last String: %s\n", *(char**) getVoidListTail(getVoidListTail(motherOfAllVoidLists)));

    printf("motherOfAllVoidLists is %s.\n", isEmptyVoidList(motherOfAllVoidLists) ? "EMPTY" : "NOT empty");
}