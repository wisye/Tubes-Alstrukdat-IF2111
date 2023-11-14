#include "func.h"
#include <stdio.h>

// EXTRA

void showPenyanyi(ListDefault l){
    int len = l.NEFF;
    int i=0;
    for(i=0; i<len; i++){
        printf("\t%d. %s\n", i+1, l.list_penyanyi[i].TabWord);
    }
}

int showAlbum(Word w, MapAlbum l){
    int len = l.NEFF;
    // cari indeks penyanyi di list
    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord)){
            break;
        }
    }
    // printf("indeks penyanyi %d\n", i);
    // print semua album
    int j;
    for(j=0; j < l.list_penyanyi[i].NEFF; j++){
        printf("\t%d. %s\n", j+1, l.list_penyanyi[i].list_album[j].nama_album.TabWord);
    }
    return i;
}

void showLagu(Word w, int idx_penyanyi, ListDefault l){
    int len = l.list_penyanyi[idx_penyanyi].NEFF; // cek dia ada berapa album

    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.list_penyanyi[idx_penyanyi].list_album[i].nama_album.TabWord)){
            break;
        }
    }

    int j;
    for(j=0; j < l.list_penyanyi[idx_penyanyi].list_album[i].NEFF; j++){
        printf("\t%d. %s\n", j+1, l.list_penyanyi[idx_penyanyi].list_album[i].list_lagu[j].TabWord);
    }
}

boolean ListDefaultIsEmpty(ListDefault l){
    return (l.NEFF == 0);
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