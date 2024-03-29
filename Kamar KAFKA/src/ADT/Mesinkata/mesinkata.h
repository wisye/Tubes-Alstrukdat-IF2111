/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "../Mesinkarakter/mesinkarakter.h"
#include <stdio.h>

#define wordNMax 500
#define BLANK ' '
#define lineNMax 500

typedef struct
{
   char TabWord[wordNMax]; /* container penyimpan kata, indeks yang dipakai [0..wordNMax-1] */
   int Length;
} Word;

typedef struct Line{
   char TabWord[lineNMax]; /* container penyimpan kata, indeks yang dipakai [0..wordNMax-1] */
   int Length;
} Line;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Line currentLine;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
void IgnoreMark();
void readFileLineIgnoreMark(FILE * file);
// boolean IsEOF();
void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi wordNMax, maka sisa kata "dipotong" */

void readFileWord(FILE * f);
/* BACA DARI FILE PER BARIS SEPERTI FGETS NAMUN MENGGUNAKAN PRIMITIF MESIN KATA/MESIN KARAKTER */

void fileCopyWord();

void readFileLine(FILE * file);

void fileCopyLine();

void STARTLINE();

int stringLen(char *x);

int wordToInt(Word w);

void stringMakeEmpty(char *x);

Word charToWord(char str[]);

Line charToLine(char str[]);

void stringCopy(char *x, char *y);

boolean stringComp(char *x, char *y);

void lineCopyFromString(Line *x, char *y);

#endif