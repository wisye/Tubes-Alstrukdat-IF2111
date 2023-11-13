#ifndef album_H
#define album_H
#include "../Mesinkata/mesinkata.h"

// implementasi album menggunakan SET

#define setMaxEl 100

typedef Word setinfotype;
typedef int setaddress;

typedef struct {
    Word nama_album;
    setinfotype NamaLagu[setMaxEl];
    setaddress Count;
} Album; // 1 album simpan banyak lagu

#endif