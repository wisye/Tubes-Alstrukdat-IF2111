#include "console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    loadSpotify();
<<<<<<< HEAD
=======

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
    listSpotify(l);
>>>>>>> main
    return 0;
}