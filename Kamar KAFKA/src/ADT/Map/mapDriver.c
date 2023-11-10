#include <stdio.h>
#include "map.h"

int main() {
    Map M;
    mapCreateEmpty(&M);

    // Test mapIsEmpty
    printf("Is M empty? %d\n", mapIsEmpty(M)); // Expected output: 1 (true)

    // Test mapInsert
    mapInsert(&M, "key1", 10);
    mapInsert(&M, "key2", 20);
    mapInsert(&M, "key3", 30);
    mapInsert(&M, "key4", 40);
    mapInsert(&M, "key5", 50);

    // Test mapValue
    printf("Value of key1: %d\n", mapValue(M, "key1")); // Expected output: 10
    printf("Value of key3: %d\n", mapValue(M, "key3")); // Expected output: 30
    printf("Value of key6: %d\n", mapValue(M, "key6")); // Expected output: -999 (mapUndefined)

    // Test mapIsMember
    printf("Is key1 a member of M? %d\n", mapIsMember(M, "key1")); // Expected output: 1 (true)
    printf("Is key6 a member of M? %d\n", mapIsMember(M, "key6")); // Expected output: 0 (false)

    // Test mapDelete
    mapDelete(&M, "key3");
    printf("Is key3 a member of M after deletion? %d\n", mapIsMember(M, "key3")); // Expected output: 0 (false)

    // Test mapIsFull
    printf("Is M full? %d\n", mapIsFull(M)); // Expected output: 0 (false)

    return 0;
}