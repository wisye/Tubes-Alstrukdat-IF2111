#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;
    stackinfotype X;

    // Test stackCreateEmpty
    stackCreateEmpty(&S);
    if (stackIsEmpty(S)) {
        printf("CreateEmpty test passed.\n");
    } else {
        printf("CreateEmpty test failed.\n");
    }

    // Test Push and stackIsFull
    for (int i = 0; i < stackMaxEl; i++) {
        Push(&S, i);
    }
    if (stackIsFull(S)) {
        printf("Push and IsFull test passed.\n");
    } else {
        printf("Push and IsFull test failed.\n");
    }

    // Test Pop and stackIsEmpty
    for (int i = stackMaxEl - 1; i >= 0; i--) {
        Pop(&S, &X);
        if (X != i) {
            printf("Pop test failed.\n");
            break;
        }
    }
    if (stackIsEmpty(S)) {
        printf("Pop and IsEmpty test passed.\n");
    } else {
        printf("Pop and IsEmpty test failed.\n");
    }

    return 0;
}