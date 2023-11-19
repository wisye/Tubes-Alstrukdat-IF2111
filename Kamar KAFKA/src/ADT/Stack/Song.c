#include "stack.h"
#include "../Queue/queuedefault.c"

typedef struct current{
    char penyanyi[100];
    char album[100];
    char lagu[100];
}current;

void SongNext(Queue *q, Stack *history, current Lagu){ //asumsi variabel currentsong menyimpan idx penyanyi, album, dan lagu
    int lagu; //menyimpan ID lagu
    char lagu[100];
    char penyanyi[100]; 
    if(queueisEmpty(*q)){
            printf("Queue kosong, memutar kembali lagu\n");
            printf("\"%s\" oleh \"%s\"\n", Lagu.lagu, Lagu.penyanyi); //memutar kembali lagu yang ada di currentsong
    }
    else{
        dequeue(q, &lagu);
        Push(&history, lagu);
        Lagu = history->T[history->TOP];
        printf("Memutar lagu selanjutnya\n");
        printf("\"%s\" oleh \"%s\"\n", Lagu.lagu, Lagu.penyanyi);
    }
}
/*Memutar lagu yang berada di dalam queue*/
/*I.S. Queue bisa kosong*/

void SongPrevious(Queue *q, Stack *history, current Lagu){
    int prev, temp;
    Queue tempq;
    CreateQueue(&temp);
    if(history->TOP == 1){ //stack yang berisi 1 elemen dihitung riwayat kosong
        printf("Riwayat lagu kosong, memutar kembali lagu\n"); //memutar lagu yang berada di currentsong
        printf("\"%s\" oleh \"%s\"\n", Lagu.lagu, Lagu.penyanyi);
    }

    else{
        Pop(history, &prev);
        for(int i = 0; i < queuelength(*q); i++){ //kosongkan queue yang *q
            dequeue(q, &temp);
            enqueue(&tempq, temp);
        }
        enqueue(q, prev); //masukkan ID yang sudah di pop dari stack ke *q
        for(int i = 0; i < queuelength(tempq); i++){ //enqeue kembali ID lagu yang berada di *q sebelumnya
            dequeue(&tempq, &temp);
            enqueue(q, temp);
        }
        Lagu = history->T[history->TOP];
        printf("Memutar lagu sebelumnya\n");
        printf("\"%s\" oleh \"%s\"\n", Lagu.lagu, Lagu.penyanyi);
    }
}