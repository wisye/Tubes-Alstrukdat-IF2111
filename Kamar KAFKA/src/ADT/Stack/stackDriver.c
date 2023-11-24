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

int main(){
    Stack S;
    stackinfotype X;

    // Test stackCreateEmpty
    stackCreateEmpty(&S);
    if (stackIsEmpty(S)) {
        printf("CreateEmpty test passed.\n");
    } else {
        printf("CreateEmpty test failed.\n");
    }
    stringCopy(X.nama_penyanyi, "penyanyix");
    stringCopy(X.nama_album, "albumx");
    stringCopy(X.nama_lagu, "lagux");
    X.idx_penyanyi = 1;
    // Test Push and stackIsFull
    for (int i = 0; i < stackMaxEl; i++) {
        Push(&S, X);
    }
    if (stackIsFull(S)) {
        printf("Push and IsFull test passed.\n");
    } else {
        printf("Push and IsFull test failed.\n");
    }

    // Test Pop and stackIsEmpty
    for (int i = stackMaxEl - 1; i >= 0; i--) {
        Pop(&S, &X);
    }
    if (stackIsEmpty(S)) {
        printf("Pop and IsEmpty test passed.\n");
    } else {
        printf("Pop and IsEmpty test failed.\n");
    }

    return 0;
}