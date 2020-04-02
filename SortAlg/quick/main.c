#include <stdlib.h>
#include <stdio.h>
#include "quick.h"


int main(int argc, char *argv[])
{
	int i = 0;
	int test_arr0[] = {10, 11, 9, 255, 34, 46, 1200, 55, 23, 21, 46, 69};

	quick_sort_with_recursion(test_arr0, 12);

	for (i = 0; i < 12; i++) {
		printf("%d ", test_arr0[i]);
	}

	printf("\n");

	int test_arr1[] = {10, 11, 9, 255, 34, 46, 1200, 55, 23, 21, 46, 69};

  quick_sort_without_recursion(test_arr1, 12);

	for (i = 0; i < 12; i++) {
		printf("%d ", test_arr1[i]);
	}

	printf("\n");

	return 0;
}
