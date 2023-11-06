#include <stdio.h>
#include <stdlib.h>
#include "../ADT_H/list.h"

int main(){
    List L = MakeList();
    printf("Is list empty? %d\n", ListIsEmpty(L));
    ListElType X = 123;
    ListElType Y = 456;
    ListElType Z = 789;
    ListInsertFirst(&L, X);
    ListInsertLast(&L, Y);
    ListInsertAt(&L, Z, 1);
    printf("Is list empty? %d\n", ListIsEmpty(L));
    printf("List length: %d\n", ListLength(L));
    printf("List element at index 0: %d\n", ListGet(L, 0));
    printf("List element at index 1: %d\n", ListGet(L, 1));
    printf("List element at index 2: %d\n", ListGet(L, 2));
    printf("Is list empty? %d\n", ListIsEmpty(L));
    printf("Is index 0 valid? %d\n", ListIsIdxValid(L, 0));
    printf("Is index 3 valid? %d\n", ListIsIdxValid(L, 3));
    printf("Is index 2 efficient? %d\n", ListIsIdxEff(L, 2));
    printf("Is index 3 efficient? %d\n", ListIsIdxEff(L, 3));
    printf("Is element %d in the list? %d\n", X, ListSearch(L, X));
    printf("Is element %d in the list? %d\n", Y, ListSearch(L, Y));
    printf("Is element %d in the list? %d\n", Z, ListSearch(L, Z));
    ListDeleteFirst(&L);
    ListDeleteLast(&L);
    ListDeleteAt(&L, 0);
    printf("List length after deletion: %d\n", ListLength(L));
    return 0;
}