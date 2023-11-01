#include "mesinkata.h"

typedef struct Album{
    int NEFF;
    Word nama_album;
    Word list_lagu[100]; // banyak lagu dalam 1 album
} Album;

typedef struct Penyanyi{
    int NEFF;
    Word nama_penyanyi;
    Album list_album[10]; // banyak Album dalam 1 penyanyi
} Penyanyi;

typedef struct ListDefault{
    int NEFF;
    Penyanyi list_penyanyi[10];
} ListDefault;