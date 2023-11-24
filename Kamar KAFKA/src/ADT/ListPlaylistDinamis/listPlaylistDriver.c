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

int main(){
    ListPlaylist X;
    X = MakeArrayDin();
    printf("Apakah array kosong?\n");
    if(lpIsEmpty(X)){
        printf("true\n");
    }
    else printf("false\n");

    lList a,b,c;
    llCreateEmpty(&a);
    llCreateEmpty(&b);
    llCreateEmpty(&c);

    int capacity;
    int length;
    printf("array sekarang memiliki panjang : \n");
    length = lpLength(X);
    printf("%d\n", length);
    printf("array sekarang memiliki capacity : \n");
    capacity = lpGetCapacity(X);
    printf("%d\n", capacity);

    lpInsertLast(&X, a);
    lpInsertLast(&X, b);
    lpInsertLast(&X, c);
    printf("Print Playlist : \n");
    PrintPlaylist(X);
    printf("\n");

    printf("Delete Playlist index 2 : \n");
    lpDeleteAt(&X, 2);
    PrintPlaylist(X);
    printf("\n");

    return 0;
}