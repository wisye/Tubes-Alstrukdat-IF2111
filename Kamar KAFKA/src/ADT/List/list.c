#include "list.h"
// #include <stdio.h>

void MakeListPenyanyi(ListPenyanyi *L){
    int i, j;
    L->count = 0;
    for(i=0; i < ListPenyanyiMaxEl; i++){
        L->A[i].nama_penyanyi.TabWord[0] = '\0';
        L->A[i].nama_penyanyi.Length = 0;
        L->A[i].album.Count = 0;
        for(j=0; j < mapMaxEl; j++){
            L->A[i].album.Elements[j].nama_album.TabWord[0] = '\0';
            L->A[i].album.Elements[j].nama_album.Length = 0;
            L->A[i].album.Elements[j].daftar_lagu.Count = 0;
            for(int k=0; k < setMaxEl; k++){
                L->A[i].album.Elements[j].daftar_lagu.Elements[k].TabWord[0] = '\0';
                L->A[i].album.Elements[j].daftar_lagu.Elements[k].Length = 0;
            }
        }
    }
}

// boolean ListPenyanyiIsEmpty(ListPenyanyi L){
//     return L.count == 0;
// }

// ListPenyanyiElType ListPenyanyiGet(ListPenyanyi L, ListPenyanyiIdxType i){
//     return L.A[i];
// }

// void ListPenyanyiSet(ListPenyanyi *L, ListPenyanyiIdxType i, ListPenyanyiElType v){
//     (*L).A[i] = v;
// }

// int ListPenyanyiLength(ListPenyanyi L){
//     int i;
//     int sum = 0;
//     for(i=0; i<ListPenyanyiMaxEl; i++){
//         if(L.A[i] != ListPenyanyiMark){
//             sum++;
//         }
//         else{
//             return sum;
//         }
//     }
// }

// ListPenyanyiIdxType ListPenyanyiFirstIdx(ListPenyanyi L){
//     return 0;
// }

// ListPenyanyiIdxType ListPenyanyiLastIdx(ListPenyanyi L){
//     return ListPenyanyiLength(L)-1;
// }

// boolean ListPenyanyiIsIdxValid (ListPenyanyi L, ListPenyanyiIdxType i){
//     return ((i != -1) && (i >= 0) && (i < ListPenyanyiMaxEl));
// }

// boolean ListPenyanyiIsIdxEff (ListPenyanyi L, ListPenyanyiIdxType i){
//     return ((i >= 0) && (i < ListPenyanyiLength(L)));
// }

// boolean ListPenyanyiSearch(ListPenyanyi L, ListPenyanyiElType X){
//     int i;
//     for(i=0; i<ListPenyanyiMaxEl; i++){
//         if(L.A[i] = X){
//             return true;
//         }
//     }
//     return false;
// }

// void ListPenyanyiInsertFirst(ListPenyanyi *L, ListPenyanyiElType X){
//     int i;
//     for(i=ListPenyanyiLength(*L); i>0; i--){
//         (*L).A[i] = (*L).A[i-1];
//     }
//     (*L).A[0] = X;
// }

// void ListPenyanyiInsertAt(ListPenyanyi *L, ListPenyanyiElType X, ListPenyanyiIdxType i){
//     int idx;
//     for(idx=ListPenyanyiLength(*L); idx>i; idx--){
//         (*L).A[idx] = (*L).A[idx-1];
//     }
//     (*L).A[i] = X;
// }

// void ListPenyanyiInsertLast(ListPenyanyi *L, ListPenyanyiElType X){
//     int i=0;
//     while ((*L).A[i] != ListPenyanyiMark){
//         i++;
//     }
//     (*L).A[i] = X;
// }

// void ListPenyanyiDeleteFirst(ListPenyanyi *L){
//     int i;
//     for(i=0; i<=ListPenyanyiLength(*L); i++){
//         (*L).A[i] = (*L).A[i+1];
//     }
// }

// void ListPenyanyiDeleteAt(ListPenyanyi *L, ListPenyanyiIdxType i){
//     int idx;
//     for(idx=i; idx<=ListPenyanyiLength(*L); idx++){
//         (*L).A[idx] = (*L).A[idx+1];
//     }
//     (*L).A[i] = ListPenyanyiMark;
// }

// void ListPenyanyiDeleteLast(ListPenyanyi *L){
//     int i = 0;
//     while((*L).A[i] != ListPenyanyiMark){
//         i++;
//     }
// }

// ListPenyanyi ListPenyanyiConcat(ListPenyanyi L1, ListPenyanyi L2){
//     ListPenyanyi L3 = MakeListPenyanyi();
//     int i = 0;
//     int j = 0;
//     while((L1).A[i] != ListPenyanyiMark){
//         L3.A[i] = L1.A[i];
//         i++;
//     }
//     while((L2).A[j] != ListPenyanyiMark){
//         L3.A[i] = L2.A[j];
//         i++;
//         j++;
//     }
//     return L3;
// }

// int main(){
//     ListPenyanyi L = MakeListPenyanyi();
//     // L.A[1] = 123;
//     boolean a = IsEmpty(L);
//     printf("%d", a);
//     return 0;
// }