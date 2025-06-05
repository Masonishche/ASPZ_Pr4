#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void* logged_malloc(size_t size) {
    void* ptr = malloc(size);
    FILE *log = fopen("alloc_log.txt", "a");
    if (log) {
        time_t now = time(NULL);
        fprintf(log, "Time: %sAllocated %zu bytes at %p\n", ctime(&now), size, ptr);
        fclose(log);
    }
    return ptr;
}

int main() {
    void* p1 = logged_malloc(100);
    void* p2 = logged_malloc(200);
    free(p1);
    free(p2);
    return 0;
}
