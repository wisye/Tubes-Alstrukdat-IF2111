#include "moreADT.h"
#include <stdio.h>
// EXTRA
boolean stringComp(char *x, char *y){
    int i = 0;
    if (stringLen(x) != stringLen(y)){
        return false;
    }
    while ((x[i] != '\0') && (y[i] != '\0')){
        if (x[i] != y[i]){
            return false;
        }
        i ++;
    }
    return true;
}

void stringCopy(char *x, char *y){
    int i = 0;
    while (y[i] != '\0' && y[i] != MARK){
        // printf("%c", x[i]);
        x[i] = y[i];
        i++;
    }
}

Word charToWord(char str[]){
    Word w;
    
    int len = 0;
    while(str[len]){
        len++;
    }

    w.Length = len;

    int i;
    for(i=0; i<len;i++){
        w.TabWord[i] = str[i];
        // printf("%c\n", w.TabWord[i]);
    }

    w.TabWord[i] = '\0';

    // printf("%s\n", w.TabWord);
    return w;
}

void showPenyanyi(ListDefault l){
    int len = l.NEFF;

    int i=0;
    for(i=0; i<len; i++){
        printf("\t%d. %s\n", i+1, l.list_penyanyi[i].nama_penyanyi.TabWord);
    }
}

int showAlbum(Word w, ListDefault l){
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

int stringLen(char *x){
    int i = 0;
    while(x[i] != '\0'){
        i++;
    }
    return i;
}

int wordToInt(Word w){
    // Word numWord;
    // numWord.Length = 0;

    int i = 0;
    // while((w.TabWord[i] != MARK) && (w.TabWord[i] != '\0') && (w.TabWord[i] != BLANK) && (i < wordNMax)){
    //     numWord.TabWord[i] = w.TabWord[i];
    //     ADV();
    //     i ++;
    // }
    // printf("%s\n", numWord.TabWord);
    // numWord.Length = i;
    // printf("%d\n", numWord.Length);
    int num=0;

    int j=1;
    for(i=currentWord.Length-1; i>=0; i--){
        num += ((int) currentWord.TabWord[i] - '0') * j;
        j *= 10;
    }
    // printf("%d\n", num);
    return num;
}

void stringMakeEmpty(char *x){
    int i = 0;
    while(x[i] != '\0'){
        x[i] = '\0';
        i++;
    }

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