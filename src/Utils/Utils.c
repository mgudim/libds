#include <stdio.h>


int compareInts(void* a, void* b) {
    return (int) ((int) a > (int) b);
}


void printInt(void* a) {
    printf("%d", (int) a);
    return;
}
