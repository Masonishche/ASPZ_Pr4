#include <stdlib.h>
#include <stdio.h>

int main() {
    void *ptr = NULL;
    for (int i = 0; i < 3; i++) {
        if (!ptr)
            ptr = malloc(128);
        printf("Using ptr iteration %d: %p\n", i, ptr);
        free(ptr);  // freed here
        // ptr not set to NULL: use-after-free risk
    }

    // Corrected version:
    printf("\n--- Corrected version ---\n");
    for (int i = 0; i < 3; i++) {
        void *safe_ptr = malloc(128);
        printf("Using safe_ptr iteration %d: %p\n", i, safe_ptr);
        free(safe_ptr);
    }

    return 0;
}
