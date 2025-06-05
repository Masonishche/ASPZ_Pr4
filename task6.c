#include <stdio.h>
#include <stdlib.h>

int main() {
    char *a = realloc(NULL, 100); // like malloc
    if (a) {
        printf("realloc(NULL, 100) succeeded: %p\n", a);
    }

    char *b = realloc(a, 0);  // may free or return non-NULL
    if (!b) {
        printf("realloc(ptr, 0) returned NULL\n");
    } else {
        printf("realloc(ptr, 0) returned non-NULL: %p\n", b);
        free(b); // safe to call
    }

    return 0;
}
