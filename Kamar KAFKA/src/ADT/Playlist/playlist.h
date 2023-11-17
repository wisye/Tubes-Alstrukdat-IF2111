#ifndef listlinier_H
#define listlinier_H
#define lladdress

#include "../Mesinkata/mesinkata.h"
#include "../Penyanyi/Penyanyi.h"
#include "../Album/album.h"
#include "../boolean.h"

#define llNil NULL

typedef struct lltElmtlist * lladdress;

typedef struct lltElmtlist { 
  int count;
  Line Penyanyi.song.nama_penyanyi;
  Line Penyanyi.song.album.song.nama_album
  Line Penyanyi.song.album.song.daftar_lagu.Song
 lladdress next;
} llElmtList;

typedef struct {
lladdress linkedlistFirst;
} lList;

/* Definisi list : */
/* lList kosong : llFirst(L) = llNil */
/* Setiap elemen dengan lladdress P dapat diacu llInfo(P), llNext(P) */
/* Elemen terakhir list : jika addressnya Last, maka llNext(Last)=llNil */
#define llInfo(P) (P)->info
#define llNext(P) (P)->next
#define llFirst(L) ((L).linkedlistFirst)

#endif