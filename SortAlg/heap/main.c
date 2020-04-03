#include <stdlib.h>
#include <stdio.h>
#include "heapSort.h"

int main(int argc, char *argv[])
{
	int i = 0;
	int test_arr[] = {10, 11, 9, 255, 34, 46, 1200, 55, 23, 21, 46, 69};

	heap_sort(test_arr, 12);

	for (i = 0; i < 12; i++) {
		printf("%d ", test_arr[i]);
	}

	printf("\n");

  return 0;
}
