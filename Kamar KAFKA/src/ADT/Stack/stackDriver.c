#include <stdio.h>
#include "stack.h"

int main() {
    Stack S;
    infotype X;

    // Test CreateEmpty
    CreateEmpty(&S);
    if (IsEmpty(S)) {
        printf("CreateEmpty test passed.\n");
    } else {
        printf("CreateEmpty test failed.\n");
    }

    // Test Push and IsFull
    for (int i = 0; i < MaxEl; i++) {
        Push(&S, i);
    }
    if (IsFull(S)) {
        printf("Push and IsFull test passed.\n");
    } else {
        printf("Push and IsFull test failed.\n");
    }

    // Test Pop and IsEmpty
    for (int i = MaxEl - 1; i >= 0; i--) {
        Pop(&S, &X);
        if (X != i) {
            printf("Pop test failed.\n");
            break;
        }
    }
    if (IsEmpty(S)) {
        printf("Pop and IsEmpty test passed.\n");
    } else {
        printf("Pop and IsEmpty test failed.\n");
    }

    return 0;
}