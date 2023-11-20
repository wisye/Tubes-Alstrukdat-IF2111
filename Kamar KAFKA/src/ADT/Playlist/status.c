#include <stdio.h>
#include "playlist.h"
#include "../globalvar/globalvar.h"
#include "../Penyanyi/Penyanyi.h"
#include "../Stack/stack.h"
#include "../globalvar/globalvar.h"
#include "../Album/album.h"
#include "../Queue/queue.h"

void statusSpotify(Queue *q){
    char val = CurrentSong;
    Queue q2 = (*q);
    if (CurrentSong == NULL){
        printf ("Now Playing:");
        printf("No songs have been played yet. Please search for a song to begin playback.");

        printf("Queue:");
        printf("Your queue is empty.");
    }
    else if (CurrentSong != NULL && queueisEmpty){
        printf ("Now Playing:");
        printf("%d. %s - &s - %s\n", i+1, CurrentSong.nama_penyanyi.TabWord, CurrentSong.nama_album.TabWord, CurrentSong.lagu.TabWord); // Coldplay - Up&Up - A Head Full of Dreams

        printf("Queue:");
        printf("Your queue is empty.");
    }
    else if (!stackIsEmpty && !queueisEmpty) {
        printf ("Now Playing:");
        printf("%d. %s - &s - %s\n", i+1, CurrentSong.nama_penyanyi.TabWord, CurrentSong.nama_album.TabWord, CurrentSong.lagu.TabWord);

        printf("Queue:");
        for (int i = 0; i < queuelength ; i++){
            dequeue(*q2, val); // dequeue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - &s - %s\n", i+1, val.nama_penyanyi.TabWord, val.nama_album.TabWord, val.lagu.TabWord);
        }

    }
    else if(!stackIsEmpty && !queueisEmpty && CurrentPlaylist != NULL){
        printf("Current Playlist: %s", CurrentPlaylist);
        printf ("Now Playing:");
        printf("%d. %s - &s - %s\n", i+1, CurrentSong.nama_penyanyi.TabWord, CurrentSong.nama_album.TabWord, CurrentSong.lagu.TabWord);

    

        printf("Queue:");
        for (int i = 0; i < queuelength ; i++){
            dequeue(*q2, val); // dequeue nama_penyanyi, nama_album, CurrentSong
            printf("%d. %s - &s - %s\n", i+1, val.nama_penyanyi.TabWord, val.nama_album.TabWord, val.lagu.TabWord);
        }
    }
}


