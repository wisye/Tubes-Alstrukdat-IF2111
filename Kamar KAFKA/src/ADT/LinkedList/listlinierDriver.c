#include <stdio.h>
#include "listlinier.h"

int main() {
    lList L;
    llinfotype X;
    lladdress P;

    // Test llCreateEmpty and IsEmpty
    llCreateEmpty(&L);
    printf("Is list empty? %d\n", IsEmpty(L)); // Expected output: 1 (true)

    // Test llInsVFirst and llInsVLast
    llInsVFirst(&L, 10);
    llInsVLast(&L, 20);
    llInsVFirst(&L, 5);
    llInsVLast(&L, 30);
    printf("lList after inserting values: ");
    llPrintInfo(L); // Expected output: 5 10 20 30

    // Test llDelVFirst and llDelVLast
    llDelVFirst(&L, &X);
    llDelVLast(&L, &X);
    printf("lList after deleting first and last values: ");
    llPrintInfo(L); // Expected output: 10 20

    // Test llInsertFirst, llInsertAfter, and llInsertLast
    P = llAlokasi(15);
    llInsertFirst(&L, P);
    P = llAlokasi(25);
    llInsertAfter(&L, P, llFirst(L));
    P = llAlokasi(35);
    llInsertLast(&L, P);
    printf("lList after inserting addresses: ");
    llPrintInfo(L); // Expected output: 15 10 25 20 35

    // Test llDelFirst, llDelP, and llDelLast
    llDelFirst(&L, &P);
    llDelP(&L, 25);
    llDelLast(&L, &P);
    printf("lList after deleting addresses: ");
    llPrintInfo(L); // Expected output: 10 20

    return 0;
}