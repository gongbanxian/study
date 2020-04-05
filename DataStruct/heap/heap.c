#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "heap.h"

#define HP_PRIV(hp) ((struct __priv_heap *)((char *)hp + sizeof(struct maxHeap)))

#define FATHER(i)          ((i) > 0 ? (((i) - 1) / 2) : 0)
#define LCHILD(i)          ((i) * 2 + 1)
#define RCHILD(i)          ((i) * 2 + 2)

#define SWAP(m, n) do {                   \
                        int t = 0;        \
                        t = *(m);         \
                        *(m) = *(n);      \
                        *(n) = t;         \
            } while(0)

struct __priv_heap {
    int *hpBuf;
    int hpBufSize;
    int hpSize;
};

/* 返回当前堆的节点数，即堆的大小 */
static inline int hpSize(struct maxHeap *hp)
{
    return HP_PRIV(hp)->hpSize;
}

/* 获取指定节点的数据 */
static int getData(struct maxHeap *hp, int idx)
{
    return HP_PRIV(hp)->hpBuf[idx];
}

/* 获取堆节点，返回节点地址 */
static inline int *getNode(struct maxHeap *hp, int idx)
{
    return &(HP_PRIV(hp)->hpBuf[idx]);
}

/* 更新heap使用的buffer的大小 */
static inline int resizeBuf(struct maxHeap *hp, int size)
{
    int *newBuf = NULL;
    int *hpBuf = NULL;

    newBuf =  (int *)malloc(size * sizeof(int));
    if (newBuf == NULL) {
        return -1;
    }

    hpBuf = HP_PRIV(hp)->hpBuf;
    memcpy((void *)newBuf, (void *)hpBuf,
            (size >= hpSize(hp) ? hpSize(hp) : size) * sizeof(int));
    HP_PRIV(hp)->hpBuf = newBuf;
    HP_PRIV(hp)->hpBufSize = size;

    free(hpBuf);
    hpBuf = NULL;

    return 0;
}

/* 下沉 */
static inline void siftDown(struct maxHeap *hp, int idx)
{
    int i = 0;

    for (i = idx; LCHILD(i) < hpSize(hp); i++) {
        if (getData(hp,LCHILD(i))  > getData(hp, i)) {
            SWAP(getNode(hp, LCHILD(i)), getNode(hp, i));
        }

        if (RCHILD(i) < hpSize(hp) &&
                getData(hp, RCHILD(i)) > getData(hp, i)) {
            SWAP(getNode(hp, RCHILD(i)), getNode(hp, i));
        }
    }

    return;
}

/* 上浮 */
static inline void siftUp(struct maxHeap *hp, int idx)
{
    int i = 0;

    for (i = idx; i > 0; i = FATHER(i)) {
        if (FATHER(i) >= 0 &&
                getData(hp, FATHER(i) < getData(hp, i))) {
            SWAP(getNode(hp, FATHER(i)), getNode(hp, i));
        }
    }

    return;
}

static inline int isFull(struct maxHeap *hp)
{
    return hpSize(hp) >= HP_PRIV(hp)->hpBufSize;
}

static int isEmpty(struct maxHeap *hp)
{
    return hpSize(hp) <= 0;
}

static int addData(struct maxHeap *hp, int data)
{
    if (isFull(hp)) {
        if (resizeBuf(hp, HP_PRIV(hp)->hpBufSize + 10)) {
            printf("NO memory available!\n");
            return -1;
        }
    }

    HP_PRIV(hp)->hpBuf[HP_PRIV(hp)->hpSize] = data;
    HP_PRIV(hp)->hpSize++;

    siftUp(hp, HP_PRIV(hp)->hpSize - 1);

    return 0;
}

static int maxData(struct maxHeap *hp)
{
    if (isEmpty(hp)) {
        printf("No data available!\n");
        return -1;
    }

    return getData(hp, 0);
}

static int extractRoot(struct maxHeap *hp)
{
    int data = 0;

    if (isEmpty(hp)) {
        printf("No data available!\n");
        return -1;
    }

    data = getData(hp, 0);

    SWAP(getNode(hp, 0), getNode(hp, hpSize(hp) - 1));
    HP_PRIV(hp)->hpSize--;

    if (!isEmpty(hp)) {
        siftDown(hp, 0);
    }

    return data;
}

static int overwriteRoot(struct maxHeap *hp, int data)
{
    int ret = 0;

    if (isEmpty(hp)) {
        addData(hp, data);
        return ret;
    }

    ret = getData(hp, 0);
    HP_PRIV(hp)->hpBuf[0] = data;
    siftDown(hp, 0);

    return ret;
}

struct maxHeap *new_heap(int size)
{
    struct maxHeap *hp = NULL;

    hp = (struct maxHeap *)malloc(sizeof(struct maxHeap) + sizeof(struct __priv_heap));
    if (hp == NULL) {
        printf("No memory available!\n");
        return NULL;
    }

    HP_PRIV(hp)->hpBuf = (int *)malloc(sizeof(int) * size);
    if (HP_PRIV(hp)->hpBuf == NULL) {
        printf("No memory available!\n");
            return NULL;
    }

    HP_PRIV(hp)->hpBufSize = size;
    HP_PRIV(hp)->hpSize = 0;

    hp->size = hpSize;
    hp->addData = addData;
    hp->getData = getData;
    hp->isEmpty = isEmpty;
    hp->maxData = maxData;
    hp->extractRoot = extractRoot;
    hp->overwriteRoot = overwriteRoot;

    return hp;
}

struct maxHeap *init_heap(int *buf, int size)
{
    struct maxHeap *hp = NULL;
    int idx = 0;

    if (buf == NULL || size == 0) {
        return NULL;
    }

    hp = new_heap(size);
    if (hp == NULL) {
        printf("New heap failed!\n");
        return NULL;
    }

    memcpy((void *)(HP_PRIV(hp)->hpBuf), (void *)buf, size * sizeof(int));
    HP_PRIV(hp)->hpSize = size;

    for (idx = FATHER(hpSize(hp) - 1); idx >= 0; idx--) {
        siftDown(hp, idx);
    }

    return hp;
}

void free_heap(struct maxHeap *hp)
{
    if (hp && HP_PRIV(hp)->hpBuf) {
        free(HP_PRIV(hp)->hpBuf);
        HP_PRIV(hp)->hpBuf = NULL;

        free(hp);
        hp = NULL;
    }

    return;
}
