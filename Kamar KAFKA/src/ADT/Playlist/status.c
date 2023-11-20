#include <stdio.h>
#include "playlist.h"
#include "../globalvar/globalvar.h"
#include "../Penyanyi/Penyanyi.h"
#include "../Stack/stack.h"
#include "../globalvar/globalvar.h"
#include "../Album/album.h"
#include "../Queue/queue.h"

void statusSpotify(Queue *q){
    queueElType val;
    Queue q2;
    if (CurrentSong == NULL){
        printf ("Now Playing:");
        printf("No songs have been played yet. Please search for a song to begin playback.");

        printf("Queue:");
        printf("Your queue is empty.");
    }
    else if (CurrentSong != NULL && queueisEmpty){
        printf ("Now Playing:");
        printf("%s", CurrentSong); // Coldplay - Up&Up - A Head Full of Dreams

        printf("Queue:");
        printf("Your queue is empty.");
    }
    else if (!stackIsEmpty && !queueisEmpty) {
        printf ("Now Playing:");
        printf("%s", CurrentSong);

        printf("Queue:");
        for (int i = 0; i < queuelength ; i++){
            dequeue(q, *val); // dequeue nama_penyanyi, nama_album, CurrentSong
            enqueue(q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
        }

    }
    else if(!stackIsEmpty && !queueisEmpty && CurrentPlaylist != NULL){
        printf("Current Playlist: %s", CurrentPlaylist);
        printf ("Now Playing:");
        printf("%s", CurrentSong);

    

        printf("Queue:");
        for (int i = 0; i < queuelength ; i++){
            dequeue(q, *val); // dequeue nama_penyanyi, nama_album, CurrentSong
            enqueue(q2, val); // enqueue nama_penyanyi, nama_album, CurrentSong
        }
    }
}


