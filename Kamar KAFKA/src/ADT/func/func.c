#include "func.h"
#include <stdio.h>

// EXTRA

void showPenyanyi(ListPenyanyi l){
    // printf("a");
    int len = l.count;
    // printf("b");
    int i=0;
    // printf("c");
    for(i=0; i<len; i++){
        // printf("d");
        printf("\t%d. %s\n", i+1, l.A[i].nama_penyanyi.TabWord);
    }
}

int showAlbum(Line w, ListPenyanyi l){
    int len = l.count;
    // cari indeks penyanyi di list
    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.A[i].nama_penyanyi.TabWord)){
            break;
        }
    }
    // printf("indeks penyanyi %d\n", i);
    // print semua album
    int j;
    for(j=0; j < l.A[i].album.Count; j++){
        printf("\t%d. %s\n", j+1, l.A[i].album.Elements[j].nama_album.TabWord);
    }
    return i;
}

void showLagu(Word w, int idx_penyanyi, ListPenyanyi l){
    int len = l.A[idx_penyanyi].album.Count; // cek dia ada berapa album

    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.A[idx_penyanyi].album.Elements[i].nama_album.TabWord)){
            break;
        }
    }

    int j;
    for(j=0; j < l.A[idx_penyanyi].album.Elements[i].daftar_lagu.Count; j++){
        printf("\t%d. %s\n", j+1, l.A[idx_penyanyi].album.Elements[i].daftar_lagu.Elements[j].TabWord);
    }
}

boolean ListPenyanyiIsEmpty(ListPenyanyi l){
    return (l.count == 0);
}





// Word lineToWord(Line l){
//     Word w;
//     while((currentChar != BLANK) && (currentChar != MARK_newline)){
//         w.TabWord[w.Length] = currentChar;
//         w.Length++;
//         ADV();
//     }
//     return w;
// }