#include <stdio.h>
#include "queue.h"

int main (){
    Queue Q;

    CreateQueue(&Q) ;

    printf("Tampilan Queue kosong: ") ;
    displayQueue(Q) ;

    printf("Apakah queue Q kosong? : %d\n", isEmpty(Q));
    printf("Panjang queue Q kosong adalah : %d\n", length(Q)) ;

    enqueue(&Q,1);
    enqueue(&Q,8);
    enqueue(&Q,2);

    printf("Berikut adalah tampilan queue Q setelah enqueue: ") ;
    displayQueue(Q) ;
    printf("Apakah queue Q kosong? : %d\n", isEmpty(Q)); // 1 = true, 0 = false
  
    while (!isFull(Q)){
        enqueue(&Q, 3) ;
    }

    printf("Tampilan queue Q full: ") ; // 1 = true, 0 = false
    displayQueue(Q) ;
    printf("Apakah queue Q penuh? : %d\n", isFull(Q));


    queueElType x ;
    dequeue(&Q,&x) ;
    printf("Value yang didequeue : %d\n" , x) ;
    dequeue(&Q,&x) ;
    printf("Value yang didequeue : %d\n" , x) ;
    dequeue(&Q,&x) ;
    printf("Value yang didequeue : %d\n" , x) ;

    printf("Tampilan Queue Q setelah dequeue: ") ;
    displayQueue(Q) ;
}