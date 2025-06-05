#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>

struct sbar {
    int id;
    char data[256];
};

int main() {
    struct sbar *ptr = reallocarray(NULL, 1000, sizeof(struct sbar));
    if (!ptr) {
        perror("Initial allocation");
        return 1;
    }

    ptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!ptr) {
        perror("Reallocation failed");
        return 1;
    }

    printf("Memory reallocated successfully\n");
    free(ptr);
    return 0;
}
