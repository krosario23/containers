#include "containers.h"

#include <stdio.h>

int main () {
    node * head = NULL;
    int x = 10;
    insert_head(&head, &x, INT);
    double y = 2.3;
    insert_head(&head, &y, DOUBLE);
    int z = 98;
    insert_head(&head, &z, CHAR);
    const char* str = "test string";
    insert_head(&head, &str, STRING);
    pair * p = new_pair(&x, INT, &z, INT);
    insert_head(&head, p, PAIR);
    bool b = false;
    insert_head(&head, &b, BOOL);

    print_list(head);
    free_list(&head);
    print_list(head);
}
