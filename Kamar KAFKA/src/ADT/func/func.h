#include "../Mesinkata/mesinkata.h"
#include "../List/list.h"
#include "../Penyanyi/penyanyi.h"

boolean stringComp(char* str1, char* str2);

void stringCopy(char* str1, char* str2);

Word charToWord(char str[]);

Line charToLine(char str[]);

void showPenyanyi(ListPenyanyi l);

int showAlbum(Line w, ListPenyanyi l);

void showLagu(Word w, int idx_penyanyi, ListPenyanyi l);

boolean ListPenyanyiIsEmpty(ListPenyanyi l);

int stringLen(char *x);

int wordToInt(Word w);

void stringMakeEmpty(char *x);
// Word lineToWord(Line l);