#include "list.h"
// #include <stdio.h>

List MakeList(){
    List L;
    int i;
    for(i=0; i < ListMaxEl; i++){
        L.A[i] = ListMark;
    }
    return L;
}

boolean ListIsEmpty(List L){
    return L.A[0] == ListMark;
}

ListElType ListGet(List L, ListIdxType i){
    return L.A[i];
}

void ListSet(List *L, ListIdxType i, ListElType v){
    (*L).A[i] = v;
}

int ListLength(List L){
    int i;
    int sum = 0;
    for(i=0; i<ListMaxEl; i++){
        if(L.A[i] != ListMark){
            sum++;
        }
        else{
            return sum;
        }
    }
}

ListIdxType ListFirstIdx(List L){
    return 0;
}

ListIdxType ListLastIdx(List L){
    return ListLength(L)-1;
}

boolean ListIsIdxValid (List L, ListIdxType i){
    return ((i != -1) && (i >= 0) && (i < ListMaxEl));
}

boolean ListIsIdxEff (List L, ListIdxType i){
    return ((i >= 0) && (i < ListLength(L)));
}

boolean ListSearch(List L, ListElType X){
    int i;
    for(i=0; i<ListMaxEl; i++){
        if(L.A[i] = X){
            return true;
        }
    }
    return false;
}

void ListInsertFirst(List *L, ListElType X){
    int i;
    for(i=ListLength(*L); i>0; i--){
        (*L).A[i] = (*L).A[i-1];
    }
    (*L).A[0] = X;
}

void ListInsertAt(List *L, ListElType X, ListIdxType i){
    int idx;
    for(idx=ListLength(*L); idx>i; idx--){
        (*L).A[idx] = (*L).A[idx-1];
    }
    (*L).A[i] = X;
}

void ListInsertLast(List *L, ListElType X){
    int i=0;
    while ((*L).A[i] != ListMark){
        i++;
    }
    (*L).A[i] = X;
}

void ListDeleteFirst(List *L){
    int i;
    for(i=0; i<=ListLength(*L); i++){
        (*L).A[i] = (*L).A[i+1];
    }
}

void ListDeleteAt(List *L, ListIdxType i){
    int idx;
    for(idx=i; idx<=ListLength(*L); idx++){
        (*L).A[idx] = (*L).A[idx+1];
    }
    (*L).A[i] = ListMark;
}

void ListDeleteLast(List *L){
    int i = 0;
    while((*L).A[i] != ListMark){
        i++;
    }
}

List ListConcat(List L1, List L2){
    List L3 = MakeList();
    int i = 0;
    int j = 0;
    while((L1).A[i] != ListMark){
        L3.A[i] = L1.A[i];
        i++;
    }
    while((L2).A[j] != ListMark){
        L3.A[i] = L2.A[j];
        i++;
        j++;
    }
    return L3;
}

// int main(){
//     List L = MakeList();
//     // L.A[1] = 123;
//     boolean a = IsEmpty(L);
//     printf("%d", a);
//     return 0;
// }