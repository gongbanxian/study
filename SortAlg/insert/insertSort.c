#include <stdlib.h>
#include "insertSort.h"


void insertSort(int *arr, int size)
{
    int unsorted_head = 0;
    int sorted_iterator = 0;
    int first_unsorted_data = 0;

    if (arr == NULL) {
        goto GO_OUT;
    }

    for (unsorted_head = 1; unsorted_head < size; unsorted_head++) {
        first_unsorted_data = arr[unsorted_head];

        for (sorted_iterator = unsorted_head - 1; sorted_iterator >= 0; sorted_iterator--) {
            if (arr[sorted_iterator] > first_unsorted_data) {
                arr[sorted_iterator + 1] = arr[sorted_iterator];
            } else {
                break;
            }
        }

        arr[sorted_iterator + 1] = first_unsorted_data;
    }

GO_OUT:
    return;
}
