#ifndef __INSERTSORT_H__
#define __INSERTSORT_H__

#include <stdio.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

void insertSort(int *arr, int size);

static inline void print_array(int *arr, int size)
{
    int i = 0;

    printf("array : \n");

    for (i = 0; i < size; i++) {
        printf("%4d ", arr[i]);

        if (i && (i % 16 == 0)) {
            printf("\n");
        }
    }

    printf("\n");
}

#endif
