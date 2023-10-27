#include <stdio.h>
#include "src/command/console.h"

boolean stringComp(char *x, char *y){
    int i = 0;
    while ((x[i] != '\0') && (y[i] != '\0')){
        if (x[i] != y[i]){
            return false;
        }
        i ++;
    }
    return true;
}

void startspotify(){
    START();
}

void help(){
    printf("START : Memulai spotify\n");
}

int main(){
    char *command;
    scanf("%s", command);
    
    if(stringComp(command, "START")){
        startspotify();
    }
    else if(stringComp(command, "HELP")){
        help();
    }
    else{
        printf("invalid command");
    }
}