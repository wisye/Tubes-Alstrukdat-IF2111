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
    SetAlbum S;
    albumCreateEmpty(&S);

    printf("%d\n", setIsEmpty(S));
    setinfotype Elmt;
    strcpy(Elmt.TabWord, "Lagu1");
    setInsert(&S, Elmt);
    strcpy(Elmt.TabWord, "Lagu2");
    setInsert(&S, Elmt);
    strcpy(Elmt.TabWord, "Lagu3");
    setInsert(&S, Elmt);
    printf("%d\n", setIsEmpty(S));

    for(int i=0; i<S.Count; i++){
        printf("%s\n", S.Elements[i].TabWord);
    }
    
    strcpy(Elmt.TabWord, "Lagu4");
    printf("%d\n", setIsMember(S, Elmt));

    strcpy(Elmt.TabWord, "Lagu2");
    printf("%d\n", setIsMember(S, Elmt));
    setDelete(&S, Elmt);

    for(int i=0; i<S.Count; i++){
        printf("%s\n", S.Elements[i].TabWord);
    }
    
}