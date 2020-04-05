#include <stdlib.h>
#include <stdio.h>

#include "heap.h"

#define ARRAY_SIZE(x)  (sizeof(x) / sizeof((x)[0]))

int main(int argc, char *argv[])
{
    struct maxHeap *hp = NULL;
    int i = 0;

    int test[] = {34, 23, 14, 55, 767, 44, 98, 12, 34, 23, 45, 66, 44, 99, 81};

    hp = init_heap(test, 5);
    if (hp == NULL) {
        printf("Init heap failed!\n");
        return -1;
    }

    for (i = 5; i < ARRAY_SIZE(test); i++) {
        if (test[i] < hp->maxData(hp)) {
            hp->overwriteRoot(hp, test[i]);
        }
    }

    for (i = 0; i < hp->size(hp); i++) {
        printf("%d ", hp->getData(hp, i));     
    }

    printf("\n");

    return 0;
}
