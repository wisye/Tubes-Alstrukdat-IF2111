#ifndef penyanyi_H
#define penyanyi_H

// implementasi penyanyi menggunakan MAP
#include "../Mesinkarakter/mesinkarakter.h"
#include "../Mesinkata/mesinkata.h"
#include "../Album/album.h"

#define mapNil 0
#define mapMaxEl 10
#define mapUndefined -999

typedef int mapaddress;

typedef struct {
    Line nama_album;
    SetAlbum daftar_lagu;
} mapinfoalbum; // 1 album simpan banyak lagu

typedef struct {
    mapinfoalbum Elements[mapMaxEl];
    mapaddress Count;
} MapAlbum;

typedef Line mapkeytype;
typedef MapAlbum mapvaluetype;


typedef struct {
	mapkeytype nama_penyanyi;
	mapvaluetype album;
} mapinfotype;

typedef struct {
	mapinfotype Elements[mapMaxEl];
	mapaddress Count;
} MapPenyanyi;

/* *** Konstruktor/Kreator *** */
void mapCreateEmpty(MapPenyanyi *M);
void mapCreateEmptyAlbum(MapAlbum *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean mapIsEmpty(MapPenyanyi M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean mapIsFull(MapPenyanyi M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
MapAlbum* mapValue(MapPenyanyi* M, mapkeytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void mapInsert(MapPenyanyi *M, mapkeytype k, mapvaluetype v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void mapInsertAlbum(MapAlbum *M, mapkeytype k, SetAlbum v);
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void mapDelete(MapPenyanyi *M, mapkeytype k);
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean mapIsMember(MapPenyanyi M, mapkeytype k);
/* Mengembalikan true jika k adalah member dari M */

boolean mapIsMemberAlbum(MapAlbum M, mapkeytype k);
/* Mengembalikan true jika k adalah member dari M */

#endif
