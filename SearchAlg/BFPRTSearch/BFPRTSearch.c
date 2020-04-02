#include <stdlib.h>
#include "BFPRTSearch.h"

#define SWAP_SAFE(x, y, t) do {        \
                                t = x; \
                                x = y; \
                                y = t; \
                        } while(0)

static inline void insertSort(int *arr, int size)
{
    int s = 0;
    int us = 0;
    int t = 0;

    if (arr == NULL) {
        return;
    }

    for (us = 1; us < size; us++) {
        t = arr[us];

        for (s = us -1; s >= 0; s--) {
            if (arr[s] > t) {
               arr[s + 1] = arr[s];
            } else {
                break;
            }
        }

        arr[s + 1] = t;
    }

    return;
}

static inline int findMid(int *arr, int le, int ri)
{
    int i = 0;
    int rnum = 0;
    int mnum = 0;

    for (i = le; i < ri - 5; i += 5)  {
        int t = 0;

        insertSort(arr + i, 5);
        SWAP_SAFE(arr[le + (i - le) / 5], arr[i + 2], t);

        mnum++;
    }

    rnum = ri - i + 1;
    if (rnum > 0) {
        int t = 0;

        insertSort(arr + i, rnum);
        SWAP_SAFE(arr[le + (i - le) / 5], arr[i + rnum / 2], t);

        mnum++;
    }

    if (mnum == 1)
        return le;

    return findMid(arr, le, le + mnum - 1);
}

static inline int partion(int *arr, int le, int ri, int p)
{
    int li = 0;
    int rj = 0;
    int t = 0;
    int idx = 0;
    int goal = 0;

    li = le;
    rj = ri;

    SWAP_SAFE(arr[li], arr[p], t);

    goal = arr[li];

    while (li < rj) {
        while (rj > li && arr[rj] > goal) {
            rj--;
        }

        arr[li] = arr[rj];

        while (li < rj && arr[li] <= goal) {
            li++;
        }
        
        arr[rj] = arr[li];
    }
    
    idx = li;
    arr[idx] = goal;
    
    return idx;
}

/**
 * 使用BFPRT算法从给定数组中找到第k大的数
 */
int BFPRTSearch(int *arr, int size, int k)
{
    int pivot = 0;
    int midx = 0;
    int num = 0;
    int le = 0;
    int ri = size - 1; 

    pivot = findMid(arr, le, ri);
    midx = partion(arr, le, ri, pivot);

    num = midx - le + 1; 

    if (num == k) {
        return arr[midx];
    } else if (num > k) {
        return BFPRTSearch(arr, midx, k);
    }

    return BFPRTSearch(arr + midx + 1, size - num, k - num);
}

