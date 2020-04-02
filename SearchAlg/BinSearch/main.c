#include <stdlib.h>
#include <stdio.h>
#include "BinSearch.h"

int main(int argc, char *argv[])
{
    int idx = 0;

    int tarr1[] = {0};
    int tarr2[] = {0, 11, 23, 34, 56, 255, 512};

    idx = BinSearch(NULL, 12, 12);
    printf("result1 : idx = %d\n", idx);

    idx = BinSearch(tarr1, ARRAY_SIZE(tarr1), 1);
    printf("result2 : idx = %d\n", idx);

    idx = BinSearch(tarr2, ARRAY_SIZE(tarr2), 12);
    printf("result3 : idx = %d\n", idx);

    idx = BinSearch(tarr1, ARRAY_SIZE(tarr1), 0);
    printf("result4 : idx = %d\n", idx);

    idx = BinSearch(tarr2, ARRAY_SIZE(tarr2), 11);
    printf("result5 : idx = %d\n", idx);

    idx = BinSearch(tarr2, ARRAY_SIZE(tarr2), 0);
    printf("result6 : idx = %d\n", idx);

    return 0;
}
