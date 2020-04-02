#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "mergeSort.h"

static inline void merge_ordered_sequence(int *arr1, int len1, int *arr2, int len2)
{
        int *sum_arr = NULL;
        int i = 0, j = 0, k = 0;

        sum_arr = (int *)malloc(sizeof(int) * (len1 + len2));
        if (!sum_arr) {
                perror("malloc");
                return;
        }

        while (k < len1 + len2) {
                if (i < len1 && arr1[i] <= arr2[j]) {
                        sum_arr[k++] = arr1[i++];
                }

                if (j < len2 && arr2[j] <= arr1[i]) {
                        sum_arr[k++] = arr2[j++];
                }

                if (i < len1 && j >= len2) {
                        sum_arr[k++] = arr1[i++];
                }

                if (j < len2 && i >= len1) {
                        sum_arr[k++] = arr2[j++];
                }
        }

        k = 0;

        while (k < len1 + len2) {
                arr1[k] = sum_arr[k];
                k++;
        }

        free(sum_arr);
        sum_arr = NULL;

        return;
}

void merge_sort(int *arr, int num)
{
        int mid = 0; 

        if (arr == NULL || num == 0 ||num == 1) 
                return;

        mid = num >> 1;

        merge_sort(arr, mid);
        merge_sort(arr + mid, num - mid);

        merge_ordered_sequence(arr, mid, arr + mid, num - mid); 

        return;
}
