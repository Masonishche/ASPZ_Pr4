#include <stdlib.h>
#include <stdio.h>

int main() {
    char *ptr = malloc(10);
    if (!ptr) {
        perror("Initial malloc");
        return 1;
    }

    char *new_ptr = realloc(ptr, (size_t)1 << 40); // 1TB
    if (!new_ptr) {
        perror("Realloc failed");
        free(ptr);  // Important: original pointer must be freed
    } else {
        ptr = new_ptr;
        printf("Realloc succeeded\n");
        free(ptr);
    }
    return 0;
}
