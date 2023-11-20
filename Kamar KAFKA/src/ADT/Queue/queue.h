/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../boolean.h"
#include "../Mesinkata/mesinkata.h"

#define queueIDX_UNDEF -1
#define queueCAPACITY 100

typedef struct {
        char nama_penyanyi[1000];
        char nama_album[100];
        int idx_lagu;
} queueElType;
/* Definisi elemen dan address */
// typedef int queueElType;
typedef struct {
	queueElType buffer[queueCAPACITY]; 
	int queueidxHead;
	int queueidxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define queueIDX_HEAD(q) (q).queueidxHead
#define queueIDX_TAIL(q) (q).queueidxTail
#define     queueHEAD(q) (q).buffer[(q).queueidxHead]
#define     queueTAIL(q) (q).buffer[(q).queueidxTail]

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai queueIDX_UNDEF */
/* - Index tail bernilai queueIDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean queueisEmpty(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean queueisFull(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu queueIDX_TAIL akan selalu di belakang queueIDX_HEAD dalam buffer melingkar*/

int queuelength(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, queueElType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi queueTAIL yang baru, queueIDX_TAIL "mundur" dalam buffer melingkar. */

void dequeue(Queue *q, queueElType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen queueHEAD pd I.S., queueIDX_HEAD "mundur";
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */


#endif