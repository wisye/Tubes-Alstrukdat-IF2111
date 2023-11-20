#ifndef STATUS_H
#define STATUS_H

#include "../boolean.h"
#include "../ListDefault/listdefault.h"

extern boolean STATUS; // setiap kali PLAY, tolong ubah STATUS jadi "true".
// kalau udah ga ada yang play, STATUS jadi "false".

extern ListDefault listPenyanyiGlobal;

extern char CurrentSong [100];
extern char CurrentPlaylist [100];

#endif