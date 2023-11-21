#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "../Mesinkata/mesinkata.h"
#include "../Penyanyi/penyanyi.h"
#include "../boolean.h"
#include <stdlib.h>

#define llNil NULL

typedef struct {
        char nama_penyanyi[1000];
        char nama_album[100];
        char nama_lagu[100];
        int idx_penyanyi;
        int idx_album;
        int idx_lagu;
} llinfotype;
typedef struct lltElmtlist * lladdress;
typedef struct lltElmtlist { 
  llinfotype info;
  lladdress next;
} llElmtList;

typedef struct {
lladdress linkedlistFirst;
Line namaPlaylist;
} lList;

/* Definisi list : */
/* lList kosong : llFirst(L) = llNil */
/* Setiap elemen dengan lladdress P dapat diacu llInfo(P), llNext(P) */
/* Elemen terakhir list : jika addressnya Last, maka llNext(Last)=llNil */
#define llInfo(P) (P)->info
#define llNext(P) (P)->next
#define llFirst(L) ((L).linkedlistFirst)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean llIsEmpty (lList L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void llCreateEmpty (lList *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
boolean llinfotypeNEQ(llinfotype a, llinfotype b);

/****************** Manajemen Memori ******************/
lladdress llAlokasi (llinfotype X);
/* Mengirimkan lladdress hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka lladdress tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, llNext(P)=llNil */
/* Jika alokasi gagal, mengirimkan llNil */
void llDealokasi (lladdress *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian lladdress P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
lladdress llSearch (lList L, llinfotype X);
/* Mencari apakah ada elemen list dengan info(P)= X */
/* Jika ada, mengirimkan lladdress elemen tersebut. */
/* Jika tidak ada, mengirimkan llNil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void llInsVFirst (lList *L, llinfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void llInsVLast (lList *L, llinfotype X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void llDelVFirst (lList *L, llinfotype *X);
/* I.S. lList L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void llDelVLast (lList *L, llinfotype *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void llInsertFirst (lList *L, lladdress P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-lladdress P sebagai elemen pertama */
void llInsertAfter (lList *L, lladdress P, lladdress Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void llInsertLast (lList *L, lladdress P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void llDelFirst (lList *L, lladdress *P);
/* I.S. lList tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* llFirst element yg baru adalah suksesor elemen pertama yang lama */
void llDelP (lList *L, llinfotype X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan info(P)=X, maka list tetap */
/* lList mungkin menjadi kosong karena penghapusan */
void llDelLast (lList *L, lladdress *P);
/* I.S. lList tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void llDelAfter (lList *L, lladdress *Pdel, lladdress Prec);
/* I.S. lList tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus llNext(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void llPrintInfo (lList L);
/* I.S. lList mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah terkecuali untuk newline di akhir output */
int llNbElmt (lList L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk llMax/llMin/rata-rata : lList tidak kosong ***/
llinfotype llMax (lList L);
/* Mengirimkan nilai info(P) yang maksimum */
lladdress llAdrMax (lList L);
/* Mengirimkan lladdress P, dengan info(P) yang bernilai maksimum */
llinfotype llMin (lList L);
/* Mengirimkan nilai info(P) yang minimum */
lladdress llAdrMin (lList L);
/* Mengirimkan lladdress P, dengan info(P) yang bernilai minimum */
float llAverage (lList L);
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/

void llInversList (lList *L);
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

void llKonkat1 (lList *L1, lList *L2, lList *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
#endif