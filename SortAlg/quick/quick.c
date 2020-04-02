#include <stdlib.h>
#include "quick.h"
#include "stack.h"

void quick_sort_with_recursion(int *num, int len)
{
	int li = 0;
	int ri = len - 1;
	int llen = 0;
	int rlen = 0;
	int goal = 0;

	if (num == NULL || len == 0)
		return;

	goal = num[0];

	while (ri - li > 0) {
		while (ri - li > 0 && num[ri] >= goal) {
			ri--;
		}

		num[li] = num[ri];

		while (ri - li > 0 && num[li] < goal) {
			li++;
		}

		num[ri] = num[li];
	}

	num[ri] = goal;
	rlen = len - 1 -ri;
	llen = ri;

	quick_sort_with_recursion(&num[0], llen);
	quick_sort_with_recursion(&num[ri + 1], rlen);

	return;
}


void quick_sort_without_recursion(int *num, int len)
{
	int li = 0;
	int ri = len - 1;
	int i = 0, j = 0;
	int goal = 0;
	stack_t st = NULL;

	if (num == NULL || len == 0)
		return;

	init_stack(&st);
	stack_push(st, ri);
	stack_push(st, li);

	while (!stack_empty(st)) {
		stack_pop(st, &li);
		stack_pop(st, &ri);
		goal = num[li];

		i = li;
		j = ri;
		while (j - i > 0) {
			while (j - i > 0 && num[j] >= goal) {
				j--;
			}

			num[i] = num[j];

			while (j - i > 0 && num[i] < goal) {
				i++;
			}

			num[j] = num[i];
		}

		num[j] = goal;

		if (j - 1 > li) {
			stack_push(st, j - 1);
			stack_push(st, li);
		}

		if (j + 1 < ri)	{
			stack_push(st, ri);
			stack_push(st, j + 1);
		}
    }

	delete_stack(st);

	return;
}
