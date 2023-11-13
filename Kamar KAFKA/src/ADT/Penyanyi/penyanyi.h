#ifndef penyanyi_H
#define penyanyi_H

// implementasi penyanyi menggunakan MAP
#include "../Mesinkarakter/mesinkarakter.h"
#include "../Album/album.h"

#define mapNil 0
#define mapMaxEl 10
#define mapUndefined -999

typedef Word mapkeytype;
typedef Album mapvaluetype;
typedef int mapaddress;

typedef struct {
	mapkeytype nama_penyanyi;
	mapvaluetype album;
} mapinfotype;

typedef struct {
	mapinfotype Elements[mapMaxEl];
	mapaddress Count;
} MapPenyanyi;

#endif