#include "linked_list.h"
#include <stdlib.h>
int main()
{
    // create a list of some integers
    node *head = NULL;
    add_head(&head, 10);
    add_head(&head, 2);
    add_head(&head, 13);
    add_head(&head, 40);
    add_head(&head, 25);

    print_list(head);
    insertion_sort(head);
    print_list(head);

    clear_list(&head);
}
