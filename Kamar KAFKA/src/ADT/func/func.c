#include "func.h"
#include <stdio.h>

// EXTRA

void showPenyanyi(ListDefault l){
    int len = l.Penyanyi.Count;
    int i=0;
    for(i=0; i<len; i++){
        printf("\t%d. %s\n", i+1, l.Penyanyi.Elements[i].nama_penyanyi.TabWord);
    }
}

int showAlbum(Word w, ListDefault l){
    int len = l.Penyanyi.Count;
    // cari indeks penyanyi di list
    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.Penyanyi.Elements[i].nama_penyanyi.TabWord)){
            break;
        }
    }
    // printf("indeks penyanyi %d\n", i);
    // print semua album
    int j;
    for(j=0; j < l.Penyanyi.Elements[i].album.Count; j++){
        printf("\t%d. %s\n", j+1, l.Penyanyi.Elements[i].album.Elements[j].nama_album.TabWord);
    }
    return i;
}

void showLagu(Word w, int idx_penyanyi, ListDefault l){
    int len = l.Penyanyi.Elements->album.Count; // cek dia ada berapa album

    int i;
    for(i=0; i<len; i++){
        // printf("ini cek --> %s %s\n", w.TabWord, l.list_penyanyi[i].nama_penyanyi.TabWord);
        if(stringComp(w.TabWord, l.Penyanyi.Elements[idx_penyanyi].album.Elements[i].nama_album.TabWord)){
            break;
        }
    }

    int j;
    for(j=0; j < l.Penyanyi.Elements[idx_penyanyi].album.Elements[i].daftar_lagu.Count; j++){
        printf("\t%d. %s\n", j+1, l.Penyanyi.Elements[idx_penyanyi].album.Elements[i].daftar_lagu.Elements[j].TabWord);
    }
}

boolean ListDefaultIsEmpty(ListDefault l){
    return (l.Penyanyi.Count == 0);
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