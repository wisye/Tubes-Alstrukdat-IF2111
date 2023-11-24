#include <stdio.h>
#include "welcome.h"
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
    boolean success;
    // printf("SELAMAT DATANG DI APLIKASI WAYANG WAVE\n");
    welcome();

    
    for(;;){
        printf(">> ");
        STARTWORD();
        // printf("%s\n", currentWord.TabWord);
        if(stringComp(currentWord.TabWord, "START")){
            startSpotify(&q, &s, &LPlaylist);
            break;
        }
        else if(stringComp(currentWord.TabWord, "HELP")){
            helpSpotifyBeforeLoad();
        }
        else if(stringComp(currentWord.TabWord, "LOAD")){
            loadSpotify(&q, &s, &LPlaylist, &success);
            if(success == true){
            break;
            }
        }
        else{
            STARTLINE();
            printf("Command tidak bisa dieksekusi\n");
        }
        // ADVWORD();
    }
    printf("GUNAKAN \"HELP;\" UNTUK MELIHAT DAFTAR COMMAND\n");
    for(;;){
        printf(">> ");
        STARTWORD();
        if(stringComp(currentWord.TabWord, "LIST")){
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
        else if(stringComp(currentWord.TabWord, "disq")){
            displayQueue(q);
        }
        else if(stringComp(currentWord.TabWord, "dislp")){
            PrintPlaylist(LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "SAVE")){
            saveSpotify(&q, &s, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "QUIT")){
            quitSpotify(&q, &s, &LPlaylist);
        }
        else if(stringComp(currentWord.TabWord, "HELP")){
            helpSpotifyAfterLoad();
        }
        else if(stringComp(currentWord.TabWord, "LOAD")){
            printf("Command tidak bisa dieksekusi\n");
        }
        else{
            STARTLINE();
            printf("Command tidak diketahui!\n");
        }
    }
}