#include <stdio.h>
#include "src/command/console.h"
// #include "src/command/func.h"

void startspotify(){
    START();
}

void help(){
    printf("START : Memulai spotify\n");
}

int main(){
    ListDefault l;

    for(;;){
        printf(">> ");
        STARTWORD();
        
        if(stringComp(currentWord.TabWord, "START")){
            startspotify();
        }
        else if(stringComp(currentWord.TabWord, "HELP")){
            help();
        }
        else if(stringComp(currentWord.TabWord, "LOAD")){
            loadSpotify();
        }
        else if(stringComp(currentWord.TabWord, "LIST")){
            listSpotify(l);
        }
        else if(stringComp(currentWord.TabWord, "QUIT")){
            quitSpotify();
        }
        else if(stringComp(currentWord.TabWord, "SAVE")){
            saveSpotify();
        }
        else{
            printf("invalid command\n");
        }
        // ADVWORD();
    }
}