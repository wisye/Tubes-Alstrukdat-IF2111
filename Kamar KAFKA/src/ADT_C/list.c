#include "../ADT_H/list.h"
#include <stdio.h>

List MakeList(){
    List L;
    int i;
    for(i=0; i < MaxEl; i++){
        L.A[i] = Mark;
    }
    return L;
}

boolean IsEmpty(List L){
    return L.A[0] == Mark;
}

ElType Get(List L, IdxType i){
    return L.A[i];
}

void Set(List *L, IdxType i, ElType v){
    (*L).A[i] = v;
}

int Length(List L){
    int i;
    int sum = 0;
    for(i=0; i<MaxEl; i++){
        if(L.A[i] != Mark){
            sum++;
        }
        else{
            return sum;
        }
    }
}

IdxType FirstIdx(List L){
    return 0;
}

IdxType LastIdx(List L){
    return Length(L)-1;
}

boolean IsIdxValid (List L, IdxType i){
    return ((i != -1) && (i >= 0) && (i < MaxEl));
}

boolean IsIdxEff (List L, IdxType i){
    return ((i >= 0) && (i < Length(L)));
}

boolean Search(List L, ElType X){
    int i;
    for(i=0; i<MaxEl; i++){
        if(L.A[i] = X){
            return true;
        }
    }
    return false;
}

void InsertFirst(List *L, ElType X){
    int i;
    for(i=Length(*L); i>0; i--){
        (*L).A[i] = (*L).A[i-1];
    }
    (*L).A[0] = X;
}

void InsertAt(List *L, ElType X, IdxType i){
    int idx;
    for(idx=Length(*L); idx>i; idx--){
        (*L).A[idx] = (*L).A[idx-1];
    }
    (*L).A[i] = X;
}

void InsertLast(List *L, ElType X){
    int i=0;
    while ((*L).A[i] != Mark){
        i++;
    }
    (*L).A[i] = X;
}

void DeleteFirst(List *L){
    int i;
    for(i=0; i<=Length(*L); i++){
        (*L).A[i] = (*L).A[i+1];
    }
}

void DeleteAt(List *L, IdxType i){
    int idx;
    for(idx=i; idx<=Length(*L); idx++){
        (*L).A[idx] = (*L).A[idx+1];
    }
    (*L).A[i] = Mark;
}

void DeleteLast(List *L){
    int i = 0;
    while((*L).A[i] != Mark){
        i++;
    }
}

List Concat(List L1, List L2){
    List L3 = MakeList();
    int i = 0;
    int j = 0;
    while((L1).A[i] != Mark){
        L3.A[i] = L1.A[i];
        i++;
    }
    while((L2).A[j] != Mark){
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