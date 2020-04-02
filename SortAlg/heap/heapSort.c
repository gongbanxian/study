#include <stdlib.h>
#include "heapSort.h"

/* 由父亲索引计算得出左孩子索引 */
#define LCHILD(f)   (2 * (f) + 1)

/* 由父亲索引计算得出右孩子索引 */
#define RCHILD(f)   (2 * (f) + 2)

/* 由孩子索引计算得出父亲索引 */
#define FATHER(c)   ((c) ? (((c) & 0x1) ? (((c) - 1) >> 1) : (((c) >> 1) - 1)) : (c))

/* 交换两个数 */
#define SWAP(m, n)  do {                      \
                        (m) = (m) ^ (n);      \
                        (n) = (m) ^ (n);      \
                        (m) = (m) ^ (n);      \
                      } while(0)

/* 构造堆 */
void construct_heap(int *arr, int num)
{
       int i = 0;

#if 0
       for (i = num - 1; i >  0; i--) {
               if (arr[FATHER(i)] < arr[i]) {
                       SWAP(arr[FATHER(i)], arr[i]);
               }
       }
#else
       for (i = FATHER(num - 1); i >= 0; i-- ) {
              if (LCHILD(i) < num && arr[i] < arr[LCHILD(i)]) {
                     SWAP(arr[i], arr[LCHILD(i)]);
              }

              if (RCHILD(i) < num && arr[i] < arr[RCHILD(i)]) {
                     SWAP(arr[i], arr[RCHILD(i)]);
              }
       }
#endif

       return;
}

/* 堆排序 */
void heap_sort(int *arr, int num)
{
        int i = 0;

        if (arr == NULL || num == 0)
                return;

        for (i = num; i > 1; i--) {
                construct_heap(arr, i);
                SWAP(arr[0], arr[i - 1]);
        }

        return;
}
