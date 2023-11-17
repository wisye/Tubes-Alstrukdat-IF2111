#include "../Mesinkata/mesinkata.h"
#include "../ListDefault/listdefault.h"
#include "../Penyanyi/penyanyi.h"

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