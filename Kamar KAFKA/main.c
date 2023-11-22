#include <stdio.h>
#include "src/command/console.h"
// #include "src/command/func.h"

int main(){
    // int i,j,k;
    // SetAlbum lagu;
    // lagu.Count = setNil;
    // MapAlbum album;
    // album.Count = mapNil;
    // MapPenyanyi penyanyi;
    // penyanyi.Count = mapNil;
    // ListDefault l;
    // l.Penyanyi.Count = mapNil;
    // for(i=0; i<mapMaxEl; i++){
    //     l.Penyanyi.Elements[i].album.Count = mapNil;
    //     for(j=0; j<mapMaxEl; j++){
    //         l.Penyanyi.Elements[i].album.Elements[j].daftar_lagu.Count = setNil;
    //     }
    // }

    // l.Penyanyi.Count = 0;
    // l.Penyanyi.Elements = NULL;
    Queue q;
    CreateQueue(&q);
    Stack s;
    stackCreateEmpty(&s);
    ListPlaylist LPlaylist = MakeArrayDin();
    printf("SELAMAT DATANG DI APLIKASI WAYANG WAVE\n");

    
    for(;;){
        printf(">> ");
        STARTWORD();
        // printf("%s\n", currentWord.TabWord);
        if(stringComp(currentWord.TabWord, "START")){
            startSpotify(&q, &s, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "HELP")){
            helpSpotify();
        }
        else if(stringComp(currentWord.TabWord, "LOAD")){
            loadSpotify(&q, &s, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "LIST")){
            listSpotify(&LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "PLAY")){
            playSpotify(&s, &q, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "QUEUE")){
            queueSpotify(&q, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "SONG")){
            songSpotify(&q, &s);
        }
        else if(stringComp(currentWord.TabWord, "PLAYLIST")){
            playlistSpotify(&LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "STATUS")){
            statusSpotify(&q, &s);
        }
        else if(stringComp(currentWord.TabWord, "QUIT")){
            quitSpotify(&q, &s, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "disq")){
            displayQueue(q);
        }
        else if(stringComp(currentWord.TabWord, "dislp")){
            PrintPlaylist(LPlaylist);
        }
        else{
            printf("invalid command\n");
        }
        // ADVWORD();
    }
}