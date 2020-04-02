#include <stdlib.h>
#include <stdio.h>

#include "BFPRTSearch.h"

#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))

int main(int argc, char *argv[])
{
    int testa[] = {3, 15, 3, 4, 2, 6, 7, 4, 44, 32, 26, 17, 33, 128, 33, 36, 2, 
                    45, 25, 15, 4, 3, 7, 128, 129, 356, 34, 32, 1024};
    int k = 29;
    int var = 0;
    int i = 0;

    while (k) {
        for (i = 0; i < ARRAY_SIZE(testa); i++) {
            printf("%d ", testa[i]);
        }
        printf("\n");

        var = BFPRTSearch(testa, ARRAY_SIZE(testa), k);

        for (i = 0; i < ARRAY_SIZE(testa); i++) {
            printf("%d ", testa[i]);
        }
        printf("\n");

        printf("the kth val(%d) = %d\n", k, var);

        k--;
    }

    return 0;
}
