#ifndef __HEAP_H__
#define __HEAP_H__

struct maxHeap {
    int (*size)(struct maxHeap *); 
    int (*addData)(struct maxHeap *, int);
    int (*getData)(struct maxHeap *, int);
    int (*isEmpty)(struct maxHeap *);
    int (*maxData)(struct maxHeap *);
    int (*extractRoot)(struct maxHeap *);
    int (*overwriteRoot)(struct maxHeap *, int);
};

struct maxHeap *new_heap(int size);
struct maxHeap *init_heap(int *buf, int size);
void free_heap(struct maxHeap *hp);

#endif
