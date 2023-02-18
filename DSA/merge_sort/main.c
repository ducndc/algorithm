#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>
int main(int argc, const char * argv[])
{
    linked_list list;
    list.head = NULL;
    list.n = 0;

    add_head(&list, 10);
    add_head(&list, 8);
    add_head(&list, 3);
    add_head(&list, 40);
    add_head(&list, 15);
    add_head(&list, 7);

    print_list(list);

    merge_sort(&list);
    print_list(list);
}