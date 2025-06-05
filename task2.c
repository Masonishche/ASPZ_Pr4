#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    int32_t xa = 50000;
    int32_t xb = 50000;
    int32_t num = xa * xb;

    printf("num = %d\n", num);  // May overflow

    void *ptr = malloc(num);
    if (ptr) {
        printf("Allocation succeeded (unexpected).\n");
        free(ptr);
    } else {
        perror("Allocation failed");
    }

    return 0;
}
