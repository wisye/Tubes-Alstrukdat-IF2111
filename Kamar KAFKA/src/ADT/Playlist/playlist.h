#ifndef listlinier_H
#define listlinier_H

#include "../Mesinkata/mesinkata.h"
#include "../Penyanyi/penyanyi.h"
#include "../boolean.h"

#define llNil NULL

typedef struct lltElmtlist * lladdress;
typedef struct lltElmtlist { 
  int count;
  MapPenyanyi Penyanyi;
  lladdress next;
} llElmtList;

typedef struct {
  Line namaPlaylist;
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