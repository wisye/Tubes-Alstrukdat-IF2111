#include "src/ADT/Mesinkata/mesinkata.h"
#include "src/ADT/List/list.h"
#include "src/ADT/Queue/queue.h"
#include "src/ADT/Stack/stack.h"
#include "src/ADT/func/func.h"
#include "src/ADT/Album/album.h"
#include "src/ADT/globalvar/globalvar.h"
#include "src/ADT/Penyanyi/penyanyi.h"
#include "src/ADT/Playlist/playlist.h"
#include "src/ADT/ListPlaylistDinamis/listPlaylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define debug printf("--------\n")

int main(){
    // initiate nama penyanyi 1
    Line penyanyi;
    // penyanyi = charToWord("ed sheeran");
    stringCopy(penyanyi.TabWord, "ed sheeran");

    // initiate nama album 1
    Line album1;
    // album1 = charToWord("album1");
    stringCopy(album1.TabWord, "alubm1");

    // initiate set album 1
    SetAlbum s;
    albumCreateEmpty(&s);

    Line w;
    // w = charToWord("castle on the hill");
    stringCopy(w.TabWord, "castle");

    setInsert(&s, w);
    
    // w = charToWord("lagu kedua");
    stringCopy(w.TabWord, "lagu2");

    setInsert(&s, w);

    // initiate map album 1
    

    MapAlbum ma;
    mapCreateEmptyAlbum(&ma);

    mapInsertAlbum(&ma, album1, s);

    // initiate map penyanyi

    // MapPenyanyi mp;
    // mapCreateEmpty(&mp);

    printf("%s\n", ma.Elements[0].nama_album.TabWord);
    // mapInsert(&mp, penyanyi, ma);

    debug;

    // printf("%s\n", ma.penyanyi.TabWord);
    printf("%d\n", ma.Count);
    printf("%s\n", ma.Elements[0].nama_album.TabWord);
    printf("%s\n", ma.Elements[0].daftar_lagu.Elements[0].TabWord);
    return 0;
}