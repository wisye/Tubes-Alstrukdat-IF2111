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

    char test[100];
    scanf("%s", test);

    int length;
    length = stringLen(test);
    printf("panjang string adalah %d\n", length);

    char angka[10];
    scanf("%s", angka);
    int iangka;
    Word angk;
    angk = charToWord(angka);
    iangka = wordToInt(angk);
    printf("angka adalah %d\n", iangka);
 

    char test2[100];
    stringCopy(test2, test);
    printf("string copy adalah %s\n", test2);

    if(stringComp(test, test2)){
        printf("string sama\n");
    }
    else{
        printf("string beda\n");
    }

    char test3[100];
    stringMakeEmpty(test3);
    printf("string kosong adalah %s\n", test3);

    char test4[100];
    scanf("%s", test4);
    Word test5;
    test5 = charToWord(test4);
    printf("word adalah %s\n", test5.TabWord);

    Line test6;
    test6 = charToLine(test4);
    printf("line adalah %s\n", test6.TabWord);

    Line test7;
    lineCopyFromString(&test7, test4);
    printf("line copy adalah %s\n", test7.TabWord);
    return 0;
}