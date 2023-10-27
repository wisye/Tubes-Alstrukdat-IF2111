#include "../ADT_H/queue.h"
#include <stdio.h>

void CreateQueue(Queue *q){
    (*q).idxHead = IDX_UNDEF;
    (*q).idxTail = IDX_UNDEF;
}

boolean isEmpty(Queue q){
    return (q.idxHead == IDX_UNDEF);
}

boolean isFull(Queue q){
    return (((q.idxTail + 1) == q.idxHead) || (q.idxHead == 0 && q.idxTail == CAPACITY - 1));
}

int length(Queue q){
    if(isEmpty(q)){
        return 0;
    }
    else if(q.idxTail >= q.idxHead){
        return (q.idxTail - q.idxHead + 1);
    }
    else{
        return ((CAPACITY - q.idxHead) + (q.idxTail) + 1);
    }
}

void enqueue(Queue *q, ElType val){
    if (isEmpty(*q)) {
        (*q).idxHead = 0;
        (*q).idxTail = 0;
    } else {
        (*q).idxTail = ((*q).idxTail + 1) % CAPACITY;
    }
    (*q).buffer[(*q).idxTail] = val;
}

void dequeue(Queue *q, ElType *val){
    *val = (*q).buffer[(*q).idxHead];
    if ((*q).idxHead == (*q).idxTail) {
        (*q).idxHead = IDX_UNDEF;
        (*q).idxTail = IDX_UNDEF;
    } else {
        (*q).idxHead = ((*q).idxHead + 1) % CAPACITY;
    }
}

void displayQueue(Queue q){
    int i;
    if (isEmpty(q)) {
        printf("[]\n");
    } 
    else {
        printf("[");
        if (q.idxHead <= q.idxTail) {
            for (i = q.idxHead; i <= q.idxTail; i++) {
                if (i == q.idxTail) {
                    printf("%d", q.buffer[i]);
                } else {
                    printf("%d,", q.buffer[i]);
                }
            }
        } else {
            for (i = q.idxHead; i < CAPACITY; i++) {
                printf("%d,", q.buffer[i]);
            }
            for (i = 0; i <= q.idxTail; i++) {
                if (i == q.idxTail) {
                    printf("%d", q.buffer[i]);
                } else {
                    printf("%d,", q.buffer[i]);
                }
            }
        }
        printf("]\n");
    }
}