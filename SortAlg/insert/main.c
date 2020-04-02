#include <stdlib.h>
#include <stdio.h>

#include "insertSort.h"

int main(int argc, char *argv[])
{
    int testarr[] = {5, 4, 3, 7, 19, 11, 35, 5, 4, 3, 7, 19, 37,     \
                        81, 49, 55, 66, 34, 128, 255, 255, 81, 55};

    insertSort(testarr, ARRAY_SIZE(testarr));

    print_array(testarr, ARRAY_SIZE(testarr));

    return 0;
}
