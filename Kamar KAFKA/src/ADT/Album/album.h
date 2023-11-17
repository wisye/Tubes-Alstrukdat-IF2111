#ifndef album_H
#define album_H
#include "../Mesinkata/mesinkata.h"

// implementasi ADT album menggunakan ADT SET
#define setNil 0
#define setMaxEl 100
typedef Word setinfotype;
typedef int setaddress;

typedef struct {
    setinfotype Elements[setMaxEl];
    setaddress Count;
} SetAlbum;

/*
typedef struct {
    Word nama_album;
    SetAlbum daftar_lagu;
} mapinfoalbum; // 1 album simpan banyak lagu

typedef struct {
    mapinfoalbum Elements[mapMaxEl];
    mapaddress Count;
} MapAlbum;
*/


void albumCreateEmpty(SetAlbum *S);

boolean setIsEmpty(SetAlbum S);

boolean setIsFull(SetAlbum S);

void setInsert(SetAlbum *S, setinfotype Elmt);

void setDelete(SetAlbum *S, setinfotype Elmt);

boolean setIsMember(SetAlbum S, setinfotype Elmt);

#endif
