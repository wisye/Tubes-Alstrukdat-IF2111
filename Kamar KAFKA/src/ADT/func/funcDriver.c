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
    ListPenyanyi *l = (ListPenyanyi *) malloc(sizeof(ListPenyanyi));
    strcpy(l->A[0].nama_penyanyi.TabWord, "penyanyi1");
    strcpy(l->A[1].nama_penyanyi.TabWord, "penyanyi2");
    l->count = 2;
    strcpy(l->A[0].album.Elements[0].nama_album.TabWord, "p1-album1");
    strcpy(l->A[0].album.Elements[1].nama_album.TabWord, "p1-album2");
    l->A[0].album.Count = 2;
    strcpy(l->A[1].album.Elements[0].nama_album.TabWord, "p2-album1");
    l->A[1].album.Count = 1;
    strcpy(l->A[0].album.Elements[0].daftar_lagu.Elements[0].TabWord, "p1-a1-lagu1");
    strcpy(l->A[0].album.Elements[0].daftar_lagu.Elements[1].TabWord, "p1-a1-lagu2");
    strcpy(l->A[0].album.Elements[0].daftar_lagu.Elements[2].TabWord, "p1-a1-lagu3");
    l->A[0].album.Elements[0].daftar_lagu.Count = 3;
    strcpy(l->A[0].album.Elements[1].daftar_lagu.Elements[0].TabWord, "p1-a2-lagu1");
    strcpy(l->A[0].album.Elements[1].daftar_lagu.Elements[1].TabWord, "p1-a2-lagu2");
    l->A[0].album.Elements[1].daftar_lagu.Count = 2;
    strcpy(l->A[1].album.Elements[0].daftar_lagu.Elements[0].TabWord, "p2-a1-lagu1");
    strcpy(l->A[1].album.Elements[0].daftar_lagu.Elements[1].TabWord, "p2-a1-lagu2");
    strcpy(l->A[1].album.Elements[0].daftar_lagu.Elements[2].TabWord, "p2-a1-lagu3");
    strcpy(l->A[1].album.Elements[0].daftar_lagu.Elements[3].TabWord, "p2-a1-lagu4");
    l->A[1].album.Elements[0].daftar_lagu.Count = 4;
    showPenyanyi(*l);
    printf("Pilih penyanyi untuk melihat album mereka: ");
    char penyanyi[100] = "";
    stringMakeEmpty(penyanyi);
    STARTLINE();
    stringCopy(penyanyi, currentLine.TabWord);
    int idx_penyanyi = showAlbum(charToLine(penyanyi), *l);
    printf("Daftar Album oleh %s:\n", penyanyi);
    printf("Masukkan nama Album yang dipilih : ");
    char album[100] = "";
    stringMakeEmpty(album);
    STARTLINE();
    int idx_album;
    for(int i = 0; i < (*l).A[idx_penyanyi].album.Count; i++){
        if(stringComp(l->A[idx_penyanyi].album.Elements[i].nama_album.TabWord, album)){
            idx_album = i;
            break;
        }
    }
    stringCopy(album, currentLine.TabWord);
    printf("Daftar Lagu Album %s oleh %s\n", album, penyanyi);
    showLagu(charToWord(album), idx_penyanyi, *l);
    free(l);
}