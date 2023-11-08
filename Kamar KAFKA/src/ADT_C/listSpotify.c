#include <stdio.h>
// #include "list.c"
#include "../ADT_H/mesinkata.h"

#define debug printf("here worked\n")

/* LIST of STRINGS Bikinan Sendiri */

typedef struct {
    int NEFF;
    Word nama_album;
    Word list_lagu[100]; // banyak lagu dalam 1 album
} Album;

typedef struct {
    int NEFF;
    Word nama_penyanyi;
    Album list_album[10]; // banyak Album dalam 1 penyanyi
} Penyanyi;

typedef struct {
    int NEFF;
    Penyanyi list_penyanyi[10];
} ListDefault;

// #define Mark '\0'
/* END */

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


boolean stringComp(char *x, char *y){
    int i = 0;
    while ((x[i] != '\0') && (y[i] != '\0')){
        if (x[i] != y[i]){
            // printf("false here\n");
            return false;
        }
        i ++;
    }
    return true;
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

void showListDefault(ListDefault l){
    // list sudah terdefinisi
    
    printf("Daftar Penyanyi :\n");
    showPenyanyi(l);

    printf("Ingin melihat album yang ada?(Y/N): ");
    char pilihan[10];

    scanf("%s", pilihan);
    Word word_pilihan = charToWord(pilihan);
    
    printf("%s\n", word_pilihan.TabWord);

    // comparing string
    if(stringComp(word_pilihan.TabWord, "N")){
        return;
    }

    // pilih album
    printf("Pilih penyanyi untuk melihat album mereka: ");
    char penyanyi[100];
    scanf("%s", penyanyi);

    printf("%s\n", penyanyi);
    printf("Daftar Album oleh %s:\n", penyanyi);
    int idx_penyanyi = showAlbum(charToWord(penyanyi), l);


    // pilih lagu
    printf("Masukkan nama Album yang dipilih : ");
    char album[100];
    scanf("%s", album);

    printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
    showLagu(charToWord(album), idx_penyanyi, l);
}


int main(){
    /* SETUP SECTION */
    // create list of lagu
    char lagu1[2][100] = {"whistle", "boombayah"};
    char lagu2[3][100] = {"perfect", "night changes", "history"};
    char lagu3[4][100] = {"attention", "Hard To Love", "Tally", "Paint My Love"};

    Album album1;
    album1.NEFF = 2;
    Album album2;
    album2.NEFF = 3;
    Album album3;
    album3.NEFF = 4;

    char nama_album1[] = "ALBUM_1";
    char nama_album2[] = "ALBUM_2";
    char nama_album3[] = "TERBAIK";

    Penyanyi penyanyi1;
    penyanyi1.NEFF = 2;
    Penyanyi penyanyi2;
    penyanyi2.NEFF = 1;

    char nama_penyanyi1[] = "ariana_grande";
    char nama_penyanyi2[] = "Harry_Styles";

    // set up nama album;
    int j=0;
    while(j < (sizeof(nama_album1) / sizeof(nama_album1[0]))){
        album1.nama_album.TabWord[j] = nama_album1[j];
        j++;
    }
    album1.nama_album.Length = j;

    j = 0;
    while(j < (sizeof(nama_album2) / sizeof(nama_album2[0]))){
        album2.nama_album.TabWord[j] = nama_album2[j];
        j++;
    }
    album2.nama_album.Length = j;

    j = 0;
    while(j < (sizeof(nama_album3) / sizeof(nama_album3[0]))){
        album3.nama_album.TabWord[j] = nama_album3[j];
        j++;
    }
    album3.nama_album.Length = j;

    // set up list of lagu

    for(int i=0; i < (sizeof(lagu1) / sizeof(lagu1[0])); i++) {
        album1.list_lagu[i] = charToWord(lagu1[i]);
    }

    for(int i=0; i < (sizeof(lagu2) / sizeof(lagu2[0])); i++) {
        album2.list_lagu[i] = charToWord(lagu2[i]);
    }

    for(int i=0; i < (sizeof(lagu3) / sizeof(lagu3[0])); i++) {
        album3.list_lagu[i] = charToWord(lagu3[i]);
    }

    // debug;

    // set up penyanyi
    penyanyi1.nama_penyanyi = charToWord(nama_penyanyi1);
    penyanyi2.nama_penyanyi = charToWord(nama_penyanyi2);

    printf("nama penyanyi %s\n", penyanyi2.nama_penyanyi.TabWord);

    // debug;

    penyanyi1.list_album[0] = album1;
    penyanyi1.list_album[1] = album2;
    penyanyi2.list_album[0] = album3;

    printf("%s\n", penyanyi1.nama_penyanyi.TabWord);
    // debug;

    // set up list default
    ListDefault l;
    l.list_penyanyi[0] = penyanyi1;
    l.list_penyanyi[1] = penyanyi2;
    l.NEFF = 2;

    // debug;
    showListDefault(l);
}