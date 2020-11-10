#include <stdio.h>

#include "containers.h"

pair * new_pair(void * new_key, data_t key_t,
                void * new_val, data_t val_t) {
    pair * ptr = malloc(sizeof(pair));
    ptr->key = new_key;
    ptr->key_t = key_t;
    ptr->val = new_val;
    ptr->val_t = val_t;
    return ptr;
}

void print_pair(pair * p) {
    printf("("); print_value(p->key, p->key_t);
    printf(", "); print_value(p->val, p->val_t);
    printf(")");
}
