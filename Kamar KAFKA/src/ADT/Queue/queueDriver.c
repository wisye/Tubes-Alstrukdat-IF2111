#include "src/ADT/Mesinkata/mesinkata.h"
#include "src/ADT/List/list.h"
#include "src/ADT/Queue/queue.h"
#include "src/ADT/Stack/stack.h"
#include "src/ADT/func/func.h"
#include "src/ADT/Album/album.h"
#include "src/ADT/globalvar/globalvar.h"
#include "src/ADT/Penyanyi/penyanyi.h"
#include "src/ADT/Playlist/playlist.h"
#include "src/ADT/ListPlaylistDinamis/listPlaylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (){
    Queue Q;

    CreateQueue(&Q) ;

    printf("Tampilan Queue kosong: ") ;
    displayQueue(Q) ;

    printf("Apakah queue Q kosong? : %d\n", queueisEmpty(Q));
    printf("Panjang queue Q kosong adalah : %d\n", queuelength(Q)) ;

    queueElType a, b,c;
    stringCopy(a.nama_penyanyi, "penyanyia");
    stringCopy(a.nama_album, "albuma");
    stringCopy(a.nama_lagu, "lagua");
    stringCopy(b.nama_penyanyi, "penyanyib");
    stringCopy(b.nama_album, "albumb");
    stringCopy(b.nama_lagu, "lagub");
    stringCopy(c.nama_penyanyi, "penyanyic");
    stringCopy(c.nama_album, "albumc");
    stringCopy(c.nama_lagu, "laguc");
    enqueue(&Q,a);
    enqueue(&Q,b);
    enqueue(&Q,c);

    queueElType d;
    stringCopy(d.nama_penyanyi, "penyanyia");
    stringCopy(d.nama_album, "albuma");
    stringCopy(d.nama_lagu, "lagua");

    printf("Berikut adalah tampilan queue Q setelah enqueue: ") ;
    displayQueue(Q) ;
    printf("Apakah queue Q kosong? : %d\n", queueisEmpty(Q)); // 1 = true, 0 = false
  
    // while (!queueisFull(Q)){
    //     enqueue(&Q, d) ;
    // }

    printf("Tampilan queue Q full: ") ; // 1 = true, 0 = false
    displayQueue(Q) ;
    printf("Apakah queue Q penuh? : %d\n", queueisFull(Q));


    queueElType x ;
    dequeue(&Q,&x) ;
    printf("Value yang didequeue : %s\n" , x.nama_lagu) ;
    dequeue(&Q,&x) ;
    printf("Value yang didequeue : %s\n" , x.nama_lagu) ;
    dequeue(&Q,&x) ;
    printf("Value yang didequeue : %s\n" , x.nama_lagu) ;

    printf("Tampilan Queue Q setelah dequeue: ") ;
    displayQueue(Q) ;
}