#include "penyanyi.h"
/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void mapCreateEmpty(MapPenyanyi *M){
    (*M).Count = mapNil;
}
void mapCreateEmptyAlbum(MapAlbum *M){
    (*M).Count = mapNil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean mapIsEmpty(MapPenyanyi M){
    return (M.Count == mapNil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean mapIsFull(MapPenyanyi M){
    return (M.Count == mapMaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
MapAlbum* mapValue(MapPenyanyi* M, mapkeytype k){
    int i = 0;
    while(i < (*M).Count){
        if(stringComp((*M).Elements[i].nama_penyanyi.TabWord, k.TabWord)){
            return &(*M).Elements[i].album;
        }
        i++;
    }
    return NULL;
}
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */

void mapInsert(MapPenyanyi *M, mapkeytype k, mapvaluetype v){
    if (!mapIsMember(*M, k)){
        (*M).Elements[(*M).Count].nama_penyanyi = k;
        (*M).Elements[(*M).Count].album = v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void mapInsertAlbum(MapAlbum *M, mapkeytype k, SetAlbum v){
    if (!mapIsMemberAlbum(*M, k)){
        (*M).Elements[(*M).Count].nama_album = k;
        (*M).Elements[(*M).Count].daftar_lagu = v;
        (*M).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */

void mapDelete(MapPenyanyi *M, mapkeytype k){
    if(mapIsMember(*M, k)){
        int i = 0;
        while (!stringComp(M->Elements[i].nama_penyanyi.TabWord, k.TabWord)){
            i++;
        }
        i--;
        while (i < M->Count){
            M->Elements[i] = M->Elements[i+1];
            i++;
        }
        M->Count--;
    }

}
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */

boolean mapIsMember(MapPenyanyi M, mapkeytype k){
    int i = 0;
    boolean found = false;
    while (i < M.Count && !found){
        if(stringComp(M.Elements[i].nama_penyanyi.TabWord , k.TabWord)){
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika k adalah member dari M */

boolean mapIsMemberAlbum(MapAlbum M, mapkeytype k){
    int i = 0;
    boolean found = false;
    while (i < M.Count && !found){
        if(stringComp(M.Elements[i].nama_album.TabWord , k.TabWord)){
            found = true;
        }
        i++;
    }
    return found;
}

MapPenyanyi Penyanyi;