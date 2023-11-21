#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../boolean.h"
#include "../Playlist/playlist.h"

#define InitialSize 10

typedef int IdxType;
typedef lList ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} ListPlaylist;

/*
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ListPlaylist kosong dengan ukuran InitialSize
 */
ListPlaylist MakeArrayDin();

/*
 * Destruktor
 * I.S. ListPlaylist terdefinisi
 * F.S. array->A terdealokasi
 */
void lpDeallocateArrayDin(ListPlaylist *array);

/*
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean lpIsEmpty(ListPlaylist array);

/*
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int lpLength(ListPlaylist array);

/*
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
ElType Get(ListPlaylist array, IdxType i);

/*
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ListPlaylist array);

/*
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void InsertAt(ListPlaylist *array, ElType el, IdxType i);

/*
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ListPlaylist *array, ElType el);

/*
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ListPlaylist *array, ElType el);

/*
 * Fungsi untuk menghapus elemen di index ke-i ListPlaylist
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ListPlaylist *array, IdxType i);

/*
 * Fungsi untuk menghapus elemen terakhir ListPlaylist
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ListPlaylist *array);

/*
 * Fungsi untuk menghapus elemen pertama ListPlaylist
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ListPlaylist *array);

/*
 * Fungsi untuk melakukan print suatu ListPlaylist.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ListPlaylist array);

/*
 * Fungsi untuk melakukan reverse suatu ListPlaylist.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ListPlaylist *array);

/*
 * Fungsi untuk melakukan copy suatu ListPlaylist.
 * Prekondisi: array terdefinisi
 */
ListPlaylist CopyArrayDin(ListPlaylist array);

/*
 * Fungsi untuk melakukan search suatu ListPlaylist.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ListPlaylist array, Line el);

void PrintPlaylist(ListPlaylist array);



#endif