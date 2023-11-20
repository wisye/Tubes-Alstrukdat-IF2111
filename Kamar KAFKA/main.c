#include <stdio.h>
#include "src/command/console.h"
// #include "src/command/func.h"

void help(){
    printf("START : Memulai spotify\n");
}

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
    
    for(;;){
        printf(">> ");
        STARTWORD();
        // printf("%s\n", currentWord.TabWord);
        if(stringComp(currentWord.TabWord, "START")){
            startSpotify();
        }
        else if(stringComp(currentWord.TabWord, "HELP")){
            help();
        }
        else if(stringComp(currentWord.TabWord, "LOAD")){
            loadSpotify();
        }
        else if(stringComp(currentWord.TabWord, "LIST")){
            listSpotify();
        }
        else if(stringComp(currentWord.TabWord, "PLAY")){
            playSpotify();
        }
        else if(stringComp(currentWord.TabWord, "QUEUE")){
            queueSpotify(&q);
        }
        else if(stringComp(currentWord.TabWord, "SONG")){
            songSpotify();
        }
        else if(stringComp(currentWord.TabWord, "STATUS")){
            statusSpotify();
        }
        else if(stringComp(currentWord.TabWord, "QUIT")){
            quitSpotify();
        }
        else if(stringComp(currentWord.TabWord, "disq")){
            displayQueue(q);
        }
        else{
            printf("invalid command\n");
        }
        // ADVWORD();
    }
}