#include <stdio.h>
#include "set.h"

int main() {
    Set S;
    setCreateEmpty(&S);

    // Test setIsEmpty
    printf("Is S empty? %d\n", setIsEmpty(S)); // Expected output: 1 (true)

    // Test setIsFull
    printf("Is S full? %d\n", setIsFull(S)); // Expected output: 0 (false)

    // Test setInsert
    setInsert(&S, 10);
    setInsert(&S, 20);
    setInsert(&S, 30);
    printf("Is 20 a member of S? %d\n", setIsMember(S, 20)); // Expected output: 1 (true)
    printf("Is 40 a member of S? %d\n", setIsMember(S, 40)); // Expected output: 0 (false)

    // Test setDelete
    setDelete(&S, 20);
    printf("Is 20 a member of S? %d\n", setIsMember(S, 20)); // Expected output: 0 (false)

    return 0;
}