#include <stdio.h>
#include "playlist.h"
#include "../globalvar/globalvar.h"
#include "../Penyanyi/Penyanyi.h"
#include "../Stack/stack.h"
#include "../Album/album.h"
#include "../Queue/queue.h"


// help bgt benerin:(

void statusSpotify(){
    if (CurrentSong == Nil){
        printf ("Now Playing:");
        printf("No songs have been played yet. Please search for a song to begin playback.");

        printf("Queue:");
        printf("Your queue is empty.");
    }
    else if (CurrentSong != Nil && queueisEmpty){
        printf ("Now Playing:");
        printf("%s - %s -%s", nama_penyanyi, nama_album, CurrentSong); // Coldplay - Up&Up - A Head Full of Dreams

        printf("Queue:");
        printf("Your queue is empty.");
    }
    else if (!stackIsEmpty && !queueisEmpty) {
        printf ("Now Playing:");
        printf(“%s - %s -%s”, nama_penyanyi, nama_album, CurrentSong);

        printf("Queue:");
        for (int i = 0; i < queuelength ; i++){
            // dequeue nama_penyanyi, nama_album, CurrentSong
        }
    }
    else if(!stackIsEmpty && !queueisEmpty && CurrentPlaylist != Nil){
        printf("Current Playlist: %s", CurrentPlaylist);
        printf ("Now Playing:");
        printf("%s - %s -%s", nama_penyanyi, nama_album, CurrentSong);
    

        printf("Queue:");
        for (int i = 0; i < queuelength ; i++){
            // dequeue nama_penyanyi, nama_album, CurrentSong
        }
    }
}


