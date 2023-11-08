#include "../ADT_H/mesinkata.h"
// #include "../ADT_H/moreADT.h"
// #include <stdio.h>

boolean EndWord;
Word currentWord;
Line currentLine;


void IgnoreBlanks(){
    while ((currentChar == BLANK || currentChar == MARK_newline) && currentChar != EOF){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    int i;
    currentWord.Length = 0;
    for (int i=0; i<NMax; i++) {
        currentWord.TabWord[i] = '\0';
    }
    // for(i=0; i<NMax; i++){
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

    while ((currentChar != MARK) && (currentChar !=  BLANK) && (i < NMax)){
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
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void readFileWord(FILE * file){
    int i;
    currentWord.Length = 0;
    for (int i=0; i<NMax; i++) {
        currentWord.TabWord[i] = '\0';
    }
    // for(i=0; i<NMax; i++){
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
    if (currentChar == EOF) {
        EndWord = true;
    }
}

void fileCopyWord(){
    int i = 0;

    while ((currentChar != MARK)  && (currentChar != BLANK) && (currentChar != MARK_newline) && (i < NMax)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i ++;
    }

    currentWord.Length = i;
}

void readFileLine(FILE * file){
    int i;
    currentLine.Length = 0;
    for (int i=0; i<lineNMax; i++) {
        currentLine.TabWord[i] = '\0';
    }
    // for(i=0; i<NMax; i++){
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

void fileCopyLine(){
    int i = 0;

    while ((currentChar != MARK) && (currentChar != MARK_newline) && (i < lineNMax)){
        currentLine.TabWord[i] = currentChar;
        ADV();
        i ++;
    }

    currentLine.Length = i;
}

void STARTLINE(){
    int i;
    currentLine.Length = 0;
    for (int i=0; i<lineNMax; i++) {
        currentLine.TabWord[i] = '\0';
    }
    // for(i=0; i<NMax; i++){
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
