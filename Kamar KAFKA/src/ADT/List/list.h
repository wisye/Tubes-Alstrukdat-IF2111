/* MODUL ListPenyanyi INTEGER */
/* Berisi definisi dan semua primitif pemrosesan ListPenyanyi integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef ADTListPenyanyi1
#define ADTListPenyanyi1

#include "../boolean.h"
#include "../Penyanyi/penyanyi.h"

/* Kamus Umum */
#define ListPenyanyiMaxEl 10
#define ListPenyanyiMark -9999  /* Nilai tak terdefinisi */
#define ListPenyanyiInvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define ListPenyanyiIdxType int
#define ListPenyanyiElType mapinfotype

typedef struct {
	ListPenyanyiElType A[ListPenyanyiMaxEl];
	int count;  /* Memori tempat penyimpanan elemen (container) */
} ListPenyanyi;

#define ListPenyanyi(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah ListPenyanyi, cara deklarasi dan akses: */
/* Deklarasi: L : ListPenyanyi */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen ListPenyanyi
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create ListPenyanyi kosong */
void MakeListPenyanyi(ListPenyanyi * L);
/* I.S. sembarang */
/* F.S. Terbentuk ListPenyanyi L kosong dengan kapasitas ListPenyanyiMaxEl */

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test ListPenyanyi kosong *** */
// boolean ListPenyanyiIsEmpty(ListPenyanyi L);
// /* Mengirimkan true jika ListPenyanyi L kosong, mengirimkan false jika tidak */

// /* *** Menghasilkan sebuah elemen *** */
// ListPenyanyiElType ListPenyanyiGet(ListPenyanyi L, ListPenyanyiIdxType i);
// /* Prekondisi : ListPenyanyi tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
// /* Mengirimkan elemen ListPenyanyi yang ke-i */

// /* *** Selektor SET : Mengubah nilai ListPenyanyi dan elemen ListPenyanyi *** */
// void ListPenyanyiSet(ListPenyanyi *L, ListPenyanyiIdxType i, ListPenyanyiElType v);
// /* I.S. T terdefinisi, sembarang */
// /* F.S. Elemen T yang ke-i bernilai v */

// /* ********** SELEKTOR ********** */
// /* *** Banyaknya elemen *** */
// int ListPenyanyiLength(ListPenyanyi L);
// /* Mengirimkan banyaknya elemen efektif ListPenyanyi */
// /* Mengirimkan nol jika ListPenyanyi kosong */

// /* *** Selektor INDEKS *** */
// ListPenyanyiIdxType ListPenyanyiFirstIdx(ListPenyanyi L);
// /* Prekondisi : ListPenyanyi L tidak kosong */
// /* Mengirimkan indeks elemen pertama */

// ListPenyanyiIdxType ListPenyanyiLastIdx(ListPenyanyi L);
// /* Prekondisi : ListPenyanyi L tidak kosong */
// /* Mengirimkan indeks elemen terakhir */

// /* ********** Test Indeks yang valid ********** */
// boolean ListPenyanyiIsIdxValid (ListPenyanyi L, ListPenyanyiIdxType i);
// /* Prekondisi : i sembarang */
// /* Mengirimkan true jika i adalah indeks yang valid utk ukuran ListPenyanyi */
// /* yaitu antara indeks yang terdefinisi untuk container*/

// boolean ListPenyanyiIsIdxEff (ListPenyanyi L, ListPenyanyiIdxType i);
// /* Prekondisi : i sembarang*/
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk ListPenyanyi */
// /* yaitu antara FirstIdx(L)..LastIdx(L) */

// /* ********** Operasi-operasi ********** */
// boolean ListPenyanyiSearch(ListPenyanyi L, ListPenyanyiElType X);
// /* Prekondisi : X sembarang */
// /* Mengirimkan true jika terdapat elemen X di dalam ListPenyanyi */
// /* yaitu antara FirstIdx(L)..LastIdx(L) */

// void ListPenyanyiInsertFirst(ListPenyanyi *L, ListPenyanyiElType X);
// /* I.S. L terdefinisi, mungkin kosong. */
// /* F.S. v menjadi elemen pertama L. */

// void ListPenyanyiInsertAt(ListPenyanyi *L, ListPenyanyiElType X, ListPenyanyiIdxType i);
// /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
// /* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

// void ListPenyanyiInsertLast(ListPenyanyi *L, ListPenyanyiElType X);
// /* I.S. L terdefinisi, mungkin kosong. */
// /* F.S. v menjadi elemen terakhir L. */

// void ListPenyanyiDeleteFirst(ListPenyanyi *L);
// /* I.S. L terdefinisi, tidak kosong. */
// /* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

// void ListPenyanyiDeleteAt(ListPenyanyi *L, ListPenyanyiIdxType i);
// /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
// /* F.S. Elemen L pada indeks ke-i dihapus dari L. */

// void ListPenyanyiDeleteLast(ListPenyanyi *L);
// /* I.S. L terdefinisi, tidak kosong. */
// /* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

// ListPenyanyi ListPenyanyiConcat(ListPenyanyi L1, ListPenyanyi L2);
// /* Prekondisi : L1 dan L2 tidak kosong */
// /* Mengirimkan sebuah ListPenyanyi yang merupakan gabungan dari L1 dan L2 */
// /* Urutan elemen terisi dari L1, lalu L2 */
// /* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
#endif