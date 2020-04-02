#include <stdlib.h>
#include "BinSearch.h"

int BinSearch(int *arr, int size, int goal)
{
    int ri = size - 1;
    int li = 0;
    int mi = 0;

    if (arr == NULL || size <= 0) {
        return -1;
    }

    while(li <= ri) {
        mi = (ri + li) / 2;

        if (goal == arr[mi]) {
            break;
        } else if (goal < arr[mi]) {
            ri = mi - 1;
        } else if (goal > arr[mi]) {
            li = mi + 1;
        }
    }

    if (li > ri) {
        return -1;
    }

    return mi;
}
