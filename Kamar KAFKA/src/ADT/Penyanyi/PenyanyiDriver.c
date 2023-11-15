#include <stdio.h>

#include "Penyanyi.h"
#include "../Album/album.h"

#define debug printf("--------\n")

int main(){
    // initiate nama penyanyi 1
    Word penyanyi;
    penyanyi = charToWord("ed sheeran");

    // initiate nama album 1
    Word album1;
    album1 = charToWord("album1");

    // initiate set album 1
    SetAlbum s;
    albumCreateEmpty(&s);

    Word w;
    w = charToWord("castle on the hill");

    setInsert(&s, w);
    
    w = charToWord("lagu kedua");

    setInsert(&s, w);

    // initiate map album 1
    

    MapAlbum ma;
    mapCreateEmptyAlbum(&ma);

    mapInsertAlbum(&ma, album1, s);

    // initiate map penyanyi

    MapPenyanyi mp;
    mapCreateEmpty(&mp);

    printf("%s\n", ma.Elements[0].nama_album.TabWord);
    mapInsert(&mp, penyanyi, ma);

    debug;

    printf("%s\n", mp.Elements[0].nama_penyanyi.TabWord);
    printf("%d\n", mp.Elements[0].album.Count);
    printf("%s\n", mp.Elements[0].album.Elements[0].nama_album.TabWord);
    printf("%s\n", mp.Elements[0].album.Elements[0].daftar_lagu.Elements[0].TabWord);
    return 0;
}