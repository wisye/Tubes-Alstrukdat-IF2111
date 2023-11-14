#include "album.h"
#include "../func/func.h"
/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void albumCreateEmpty(SetAlbum *S){
    (*S).Count = setNil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean setIsEmpty(SetAlbum S){
    return (S.Count == setNil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean setIsFull(SetAlbum S){
    return (S.Count == setMaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void setInsert(SetAlbum *S, setinfotype Elmt){
    if (!setIsMember(*S, Elmt)){
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void setDelete(SetAlbum *S, setinfotype Elmt){
    if(setIsMember(*S, Elmt)){
        int i = 0;
        while (!stringComp(S->Elements[i].TabWord, Elmt.TabWord)){
            i++;
        }
        i--;
        while (i < S->Count){
            S->Elements[i] = S->Elements[i+1];
            i++;
        }
        S->Count--;
    }
}
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean setIsMember(SetAlbum S, setinfotype Elmt){
    int i = 0;
    boolean found = false;
    while (i < S.Count && !found){
        if (stringComp(S.Elements[i].TabWord, Elmt.TabWord)){
            found = true;
        }
        i++;
    }
    return found;
}
/* Mengembalikan true jika Elmt adalah member dari S */
