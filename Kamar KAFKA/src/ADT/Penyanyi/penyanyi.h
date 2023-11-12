#include "../Mesinkata/mesinkata.h"
#include "../Album/album.h"

typedef struct Penyanyi{
    int NEFF;
    Word nama_penyanyi;
    Album list_album[10]; // banyak Album dalam 1 penyanyi
} Penyanyi; // banyak penyanyi