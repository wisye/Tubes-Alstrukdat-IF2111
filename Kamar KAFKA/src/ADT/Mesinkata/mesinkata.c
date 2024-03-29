#include "mesinkata.h"
// #include "../ADT_H/moreADT.h"
// #include <stdio.h>

boolean EndWord;
Word currentWord;
Line currentLine;


void IgnoreBlanks(){
    while ((currentChar == BLANK || currentChar == '\n') && currentChar != EOF){
        ADV();
    }
}

void IgnoreMark(){
    while ((currentChar == MARK || currentChar == '\n') && currentChar != EOF){
        ADV();
    }
}


/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    int i;
    currentWord.Length = 0;
    for (i=0; i<wordNMax; i++) {
        currentWord.TabWord[i] = '\0';
    }
    // currentWord.Length = 0;
    // currentWord.TabWord[0] = '\0';
    // for(i=0; i<wordNMax; i++){
    //     currentWord.TabWord[i] = " ";
    // }
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        CopyWord();
    }
    // for(int j=0; j<currentWord.Length; j++) if (currentWord.TabWord[i] == '\r') printf("\r terdeteksi");
    
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;

    while ((currentChar != MARK) && (currentChar !=  BLANK) && (i < wordNMax)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    }

    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi wordNMax, maka sisa kata "dipotong" */

void readFileWord(FILE * file){
    int i;
    currentWord.Length = 0;
    for (i=0; i<wordNMax; i++) {
        currentWord.TabWord[i] = '\0';
    }
    // for(i=0; i<wordNMax; i++){
    //     currentWord.TabWord[i] = " ";
    // }
    readFileChar(file);
    IgnoreBlanks();
    if (currentChar == MARK || currentChar == EOF){
        EndWord = true;
    }
    else{
        EndWord = false;
        fileCopyWord();
    }
}

void fileCopyWord(){
    int i = 0;

    while (!IsEOF() && (currentChar != MARK)  && (currentChar != BLANK) && (currentChar != MARK_newline) && (i < wordNMax)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    }
    
    currentWord.Length = i;
}

void readFileLine(FILE * file){
    int i;
    currentLine.Length = 0;
    for (i=0; i<lineNMax; i++) {
        currentLine.TabWord[i] = '\0';
    }
    // for(i=0; i<wordNMax; i++){
    //     currentWord.TabWord[i] = " ";
    // }
    readFileChar(file);
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        fileCopyLine();
    }
}

void readFileLineIgnoreMark(FILE * file){
    int i;
    currentLine.Length = 0;
    for (i=0; i<lineNMax; i++) {
        currentLine.TabWord[i] = '\0';
    }
    // for(i=0; i<wordNMax; i++){
    //     currentWord.TabWord[i] = " ";
    // }
    readFileChar(file);
    IgnoreBlanks();
    IgnoreMark();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
    EndWord = false;
    fileCopyLine();
    }
}

void fileCopyLine(){
    int i = 0;

    while (!IsEOF() && (currentChar != MARK) && (currentChar != MARK_newline) && (i < lineNMax)){
        currentLine.TabWord[i] = currentChar;
        ADV();
        i ++;
    }
    // ADV();
    currentLine.TabWord[i] = '\0';
    currentLine.Length = i;
}

void STARTLINE(){
    int i;
    currentLine.Length = 0;
    for (i=0; i<lineNMax; i++) {
        currentLine.TabWord[i] = '\0';
    }
    // currentLine.Length = 0;
    // currentLine.TabWord[0] = '\0';
    // for(i=0; i<wordNMax; i++){
    //     currentWord.TabWord[i] = " ";
    // }
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        EndWord = true;
    }
    else{
        EndWord = false;
        fileCopyLine();
    }
}

int stringLen(char *x){
    int i = 0;
    while(x[i] != '\0'){
        i++;
    }
    return i;
}

int wordToInt(Word w){
    // Word numWord;
    // numWord.Length = 0;

    int i = 0;
    // while((w.TabWord[i] != MARK) && (w.TabWord[i] != '\0') && (w.TabWord[i] != BLANK) && (i < wordNMax)){
    //     numWord.TabWord[i] = w.TabWord[i];
    //     ADV();
    //     i ++;
    // }
    // printf("%s\n", numWord.TabWord);
    // numWord.Length = i;
    // printf("%d\n", numWord.Length);
    int num=0;

    int j=1;
    for(i=currentWord.Length-1; i>=0; i--){
        num += ((int) currentWord.TabWord[i] - '0') * j;
        j *= 10;
    }
    // printf("%d\n", num);
    return num;
}

void stringMakeEmpty(char *x){
    // int i = 0;
    // while(x[i] != '\0'){
    //     i++;
    //     x[i-1] = '\0';
    // }
    x = "";
}

Word charToWord(char str[]){
    Word w;
    
    int len = 0;
    while(str[len]){
        len++;
    }

    w.Length = len;

    int i;
    for(i=0; i<len;i++){
        w.TabWord[i] = str[i];
        // printf("%c\n", w.TabWord[i]);
    }

    w.TabWord[i] = '\0';

    // printf("%s\n", w.TabWord);
    return w;
}

Line charToLine(char str[]){
    Line w;
    
    int len = 0;
    while(str[len]){
        len++;
    }

    w.Length = len;

    int i;
    for(i=0; i<len;i++){
        w.TabWord[i] = str[i];
        // printf("%c\n", w.TabWord[i]);
    }

    w.TabWord[i] = '\0';

    // printf("%s\n", w.TabWord);
    return w;
}

void stringCopy(char *x, char *y){
    int i = 0;
    int j;
    for (j=0; j<stringLen(x); j++) {
        x[j] = '\0';
    }
    while (y[i] != '\0' && y[i] != MARK){
        // printf("%c", x[i]);
        x[i] = y[i];
        i++;
    }
    x[i] = '\0';
}

boolean stringComp(char *x, char *y){
    int i = 0;
    if (stringLen(x) != stringLen(y)){
        return false;
    }
    while ((x[i] != '\0') && (y[i] != '\0')){
        if (x[i] != y[i]){
            return false;
        }
        i ++;
    }
    return true;
}

void lineCopyFromString(Line *x, char *y){
    int i = 0;
    int j;
    for (j=0; j<lineNMax; j++) {
        x->TabWord[j] = '\0';
    }
    // printf("%s\n",x->TabWord);
    // printf("%s\n",y);
    while (y[i] != '\0' && y[i] != MARK){
        // printf("%c", x[i]);
        x->TabWord[i] = y[i];
        i++;
    }
    x->TabWord[i] = '\0';
    // printf("%s\n",x->TabWord);
    x->Length = i;
}