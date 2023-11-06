#include "mesinkata.h"



typedef struct Album{
    int NEFF;
    Word nama_album;
    Word list_lagu[100]; // banyak lagu dalam 1 album
} Album; // banyak album

typedef struct Penyanyi{
    int NEFF;
    Word nama_penyanyi;
    Album list_album[10]; // banyak Album dalam 1 penyanyi
} Penyanyi; // banyak penyanyi

typedef struct ListDefault{
    int NEFF;
    Penyanyi list_penyanyi[10];
} ListDefault;

boolean stringComp(char* str1, char* str2);

void stringCopy(char* str1, char* str2);

Word charToWord(char str[]);

void showPenyanyi(ListDefault l);

int showAlbum(Word w, ListDefault l);

void showLagu(Word w, int idx_penyanyi, ListDefault l);

boolean ListDefaultIsEmpty(ListDefault l);

int stringLen(char *x);

int wordToInt(Word w);

void stringMakeEmpty(char *x);
// Word lineToWord(Line l);