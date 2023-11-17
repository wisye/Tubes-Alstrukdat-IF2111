#ifndef __ARRAY_DINAMIK__
#define __ARRAY_DINAMIK__

#include "../Mesinkata/mesinkata.h"
#include "../Penyanyi/Penyanyi.h"
#include "../Album/album.h"

// Boolean
#define boolean unsigned char
#define true 1
#define false 0 

#define InitialSize 10

typedef int IdxType;
typedef int ElType;

typedef struct {
    Line nama_penyanyi;
    Line nama_album;
    Line daftar_lagu;
} Playlist;

#endif