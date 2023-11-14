/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../boolean.h"

#define stackNil -1
#define stackMaxEl 100
/* stackNil adalah stack dengan elemen kosong . */

typedef int stackinfotype;
typedef int stackaddress;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  stackinfotype T[stackMaxEl]; /* tabel penyimpan elemen */
  stackaddress TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = stackNil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[stackMaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define stackTop(S) (S).TOP
#define stackInfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void stackCreateEmpty(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas stackMaxEl */
/* jadi indeksnya antara 0..stackMaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai stackNil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean stackIsEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean stackIsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, stackinfotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, stackinfotype* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif