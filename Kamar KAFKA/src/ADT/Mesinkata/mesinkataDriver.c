#include "mesinkata.h"
#include <stdio.h>

int main(){
    FILE *file;
    file = fopen("test.txt", "r");
    // char buffer[100];

    // Test STARTWORD and ADVWORD
    STARTWORD();
    while(!EndWord){
        printf("%s\n", currentWord.TabWord);
        ADVWORD();
    }

    // Test STARTLINE and readFileLine
    STARTLINE();
    while(!EndWord){
        printf("%s\n", currentLine.TabWord);
        readFileLine(file);
    }

    // Test readFileWord
    readFileWord(file);
    while(!EndWord){
        printf("%s\n", currentWord.TabWord);
        readFileWord(file);
    }

    fclose(file);
    return 0;
}