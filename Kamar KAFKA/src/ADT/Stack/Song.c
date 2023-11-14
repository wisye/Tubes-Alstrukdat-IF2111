#include "stack.h"
#include "../Queue/queuedefault.c"


void SongNext(Queue *q, Stack *history){
    int lagu; //menyimpan ID lagu 
    if(queueisEmpty(*q)){
        printf("Queue kosong, memutar kembali lagu\n");
        printf("\"%s\" oleh \"%s\"\n", [namalagu di TOP], [namapenyanyi di TOP]);
    }
    else{
        dequeue(q, &lagu);
        Push(&history, lagu);
        printf("Memutar lagu selanjutya\n");
        printf("\"%s\" oleh \"%s\"\n", [namalagu di TOP], [namapenyanyi di TOP]);
    }
}
/*Memutar lagu yang berada di dalam queue*/
/*I.S. Queue bisa kosong*/

void SongPrevious(Queue *q, Stack *history){
    int prev, temp;
    Queue tempq;
    CreateQueue(&temp);
    if(history->TOP == 1){ //stack yang berisi 1 elemen dihitung riwayat kosong
        printf("Riwayat lagu kosong, memutar kembali lagu\n"); //memutar lagu yang berada di TOP
        printf("\"%s\" oleh \"%s\"\n", [namalagu di TOP], [namapenyanyi di TOP]);
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
        printf("Memutar lagu sebelumnya\n");
        printf("\"%s\" oleh \"%s\"\n", [namalagu di TOP], [namapenyanyi di TOP]);
    }
}