#include "queue.h"
#include <stdio.h>

void CreateQueue(Queue *q){
    (*q).queueidxHead = queueIDX_UNDEF;
    (*q).queueidxTail = queueIDX_UNDEF;
}

boolean queueisEmpty(Queue q){
    return (q.queueidxHead == queueIDX_UNDEF);
}

boolean queueisFull(Queue q){
    return (((q.queueidxTail + 1) == q.queueidxHead) || (q.queueidxHead == 0 && q.queueidxTail == queueCAPACITY - 1));
}

int queuelength(Queue q){
    if(queueisEmpty(q)){
        return 0;
    }
    else if(q.queueidxTail >= q.queueidxHead){
        return (q.queueidxTail - q.queueidxHead + 1);
    }
    else{
        return ((queueCAPACITY - q.queueidxHead) + (q.queueidxTail) + 1);
    }
}

void enqueue(Queue *q, queueElType val){
    if (queueisEmpty(*q)) {
        (*q).queueidxHead = 0;
        (*q).queueidxTail = 0;
    } else {
        (*q).queueidxTail = ((*q).queueidxTail + 1) % queueCAPACITY;
    }
    (*q).buffer[(*q).queueidxTail] = val;
}

void dequeue(Queue *q, queueElType *val){
    *val = (*q).buffer[(*q).queueidxHead];
    if ((*q).queueidxHead == (*q).queueidxTail) {
        (*q).queueidxHead = queueIDX_UNDEF;
        (*q).queueidxTail = queueIDX_UNDEF;
    } else {
        (*q).queueidxHead = ((*q).queueidxHead + 1) % queueCAPACITY;
    }
}

void displayQueue(Queue q){
    int i;
    if (queueisEmpty(q)) {
        printf("[]\n");
    } 
    else {
        printf("[");
        if (q.queueidxHead <= q.queueidxTail) {
            for (i = q.queueidxHead; i <= q.queueidxTail; i++) {
                printf("[");
                if (i == q.queueidxTail) {
                    printf("%d:%s,", q.buffer[i].idx_lagu, q.buffer[i].nama_lagu);
                    printf("%d:%s,", q.buffer[i].idx_album, q.buffer[i].nama_album);
                    printf("%d:%s", q.buffer[i].idx_penyanyi, q.buffer[i].nama_penyanyi);
                } else {
                    printf("%d:%s,", q.buffer[i].idx_lagu, q.buffer[i].nama_lagu);
                    printf("%d:%s,", q.buffer[i].idx_album, q.buffer[i].nama_album);
                    printf("%d:%s,", q.buffer[i].idx_penyanyi, q.buffer[i].nama_penyanyi);
                }
                printf("]");
            }
        } else {
            for (i = q.queueidxHead; i < queueCAPACITY; i++) {
                printf("[");
                    printf("%d:%s,", q.buffer[i].idx_lagu, q.buffer[i].nama_lagu);
                    printf("%d:%s,", q.buffer[i].idx_album, q.buffer[i].nama_album);
                    printf("%d:%s", q.buffer[i].idx_penyanyi, q.buffer[i].nama_penyanyi);
                printf("]");
            }
            for (i = 0; i <= q.queueidxTail; i++) {
                printf("[");
                if (i == q.queueidxTail) {
                    printf("%d:%s,", q.buffer[i].idx_lagu, q.buffer[i].nama_lagu);
                    printf("%d:%s,", q.buffer[i].idx_album, q.buffer[i].nama_album);
                    printf("%d:%s", q.buffer[i].idx_penyanyi, q.buffer[i].nama_penyanyi);
                } else {
                    printf("%d:%s,", q.buffer[i].idx_lagu, q.buffer[i].nama_lagu);
                    printf("%d:%s,", q.buffer[i].idx_album, q.buffer[i].nama_album);
                    printf("%d:%s,", q.buffer[i].idx_penyanyi, q.buffer[i].nama_penyanyi);
                }
                printf("]");
            }
        }
        printf("]\n");
    }
}