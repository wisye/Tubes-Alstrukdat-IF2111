#ifndef STATUS_H
#define STATUS_H

#include "../boolean.h"
#include "../ListDefault/listdefault.h"
#include "../Queue/queue.h"

extern boolean STATUS; // setiap kali PLAY, tolong ubah STATUS jadi "true".
// kalau udah ga ada yang play, STATUS jadi "false".
// extern ListDefault l;
// extern queue q;

extern char CurrentSong [100];
extern char CurrentPlaylist [100];

#endif