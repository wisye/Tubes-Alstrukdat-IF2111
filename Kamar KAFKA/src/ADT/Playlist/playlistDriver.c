#include "src/ADT/List/list.h"
#include "src/ADT/Queue/queue.h"
#include "src/ADT/Mesinkata/mesinkata.h"
#include "src/ADT/Stack/stack.h"
#include "src/ADT/func/func.h"
#include "src/ADT/Album/album.h"
#include "src/ADT/globalvar/globalvar.h"
#include "src/ADT/Penyanyi/penyanyi.h"
#include "src/ADT/Playlist/playlist.h"
#include "src/ADT/ListPlaylistDinamis/listPlaylist.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    lList L;
    llCreateEmpty(&L);
    printf("Is new lis empty?\n");
    if(llIsEmpty(L)){
        printf("true\n");
    }
    else printf("false\n");

    llinfotype a, b;
    stringCopy(a.nama_penyanyi, "penyanyia");
    stringCopy(a.nama_album, "albuma");
    stringCopy(a.nama_lagu, "lagua");
    stringCopy(b.nama_penyanyi, "penyanyia");
    stringCopy(b.nama_album, "albuma");
    stringCopy(b.nama_lagu, "lagua");
    printf("%s\n", a.nama_penyanyi);
    printf("%s\n", b.nama_penyanyi);
    if(!llinfotypeNEQ(a, b)){
        printf("infotype not equal\n");
    }
    else printf("infotype equal\n");

    lladdress X;
    X = llAlokasi(a);
    printf("Apakah alokasi berhasil?\n");
    if(X->info.nama_penyanyi == llNil){
        printf("true\n");
    }
    else printf("false\n");


    llInsVFirst(&L, a);
    printf("Insert a ke first list\n");
    llPrintInfo(L);
    printf("\n");

    printf("infotype b diganti menajadi penyanyib\n");
    stringCopy(b.nama_penyanyi, "penyanyib");
    stringCopy(b.nama_album, "albumb");
    stringCopy(b.nama_lagu, "lagub");

    llInsVLast(&L, b);
    printf("Insert b ke last list\n");
    llPrintInfo(L);
    printf("\n");

    printf("Apakah elemen ada 2?\n");
    printf("Elemen ada %d\n",llNbElmt(L));

    //yang llMAX, llAdrMax,llMin, llAdrMin, dan llAverage kayaknya ga perlu
    llInversList(&L);
    printf("Hasil list invers:\n");
    llPrintInfo(L);
    printf("\n");

    llinfotype c, d;
    stringCopy(c.nama_penyanyi, "penyanyic");
    stringCopy(c.nama_album, "albumc");
    stringCopy(c.nama_lagu, "laguc");
    stringCopy(d.nama_penyanyi, "penyanyid");
    stringCopy(d.nama_album, "albumd");
    stringCopy(d.nama_lagu, "lagud");
    lList Y;
    llCreateEmpty(&Y);
    llInsVFirst(&Y, c);
    llInsVFirst(&Y, d);
    printf("Ini merupakan list ke-2 :\n");
    llPrintInfo(Y);
    printf("\n");

    lList Z;
    llCreateEmpty(&Z);
    llKonkat1(&L, &Y, &Z);
    printf("Berikut hasil konkat dari list: \n");
    llPrintInfo(Z);
    printf("\n");

    lladdress del;
    llDelFirst(&Z,&del);
    printf("DelFirst elemen b\n");
    llPrintInfo(Z);
    printf("\n");

    llDelLast(&Z, &del);
    printf("DelLast elemen c\n");
    llPrintInfo(Z);

    llinfotype e, f;
    stringCopy(e.nama_penyanyi, "penyanyie");
    stringCopy(e.nama_album, "albume");
    stringCopy(e.nama_lagu, "lague");
    stringCopy(f.nama_penyanyi, "penyanyif");
    stringCopy(f.nama_album, "albumf");
    stringCopy(f.nama_lagu, "laguf");
    llInsVFirst(&Z, e);
    llInsVFirst(&Z, f);
    printf("\n");
    printf("added elemen e and f\n");
    llPrintInfo(Z);
    printf("\n");
    llDelP(&Z, e);
    printf("DelP elemen e");
    llPrintInfo(Z);
    printf("\n");

    lladdress delafter;
    delafter = llSearch(Z, a);
    llDelAfter(&Z, &del, delafter);
    printf("DelAfter elemen a");
    llPrintInfo(Z);
    printf("\n");


    return 0;
}