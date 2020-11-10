#include <stdlib.h>
#include <stdio.h>

#include "containers.h"

node * new_node(void * new_data, data_t new_type) {
    if (!valid_type(new_type)) {
        printf("insert failed, invalid data type\n");
        return NULL;
    }

    node * ptr = malloc(sizeof(node));
    ptr->data = new_data;
    ptr->next = NULL;
    ptr->type = new_type;
    return ptr;
}

bool insert_head(node ** head, void * new_data, data_t new_type) {
    node * ptr = new_node(new_data, new_type);
    if (!ptr) return false;
    ptr->next = *head;
    *head = ptr;
    return true;
}

bool delete(node ** head, size_t index) {
    if (!head) {
        printf("cannot delete from empty list\n");
        return false;
    }

    if (index == 0) {
        node * ptr = *head;
        *head = (*head)->next;
        free(ptr);
        return true;
    }

    size_t i = 1;
    node * prev = *head;
    node * curr = (*head)->next;
    while (curr != NULL) {
        if (i == index) {
            prev->next = curr->next;
            free(curr);
            return true;
        }
        prev = prev->next;
        curr = curr->next;
        ++i;
    }

    if (!curr) {
        printf("out of bounds; index %zu does not exist\n", index);
    }

    return false;
}

/* node * get_node(node * head, size_t index) {

} */

void print_list(node * head) {
    if (!head) {
        printf("cannot print empty list\n");
        return;
    }

    printf("[");
    for (node * curr = head; curr != NULL; curr = curr->next) {
        print_value(curr->data, curr->type);
        if (curr->next) printf(", ");
    }
    printf("]\n");
}

void free_list(node ** head) {
    node * ptr = *head;
    node * next;

    while (ptr) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }

    *head = NULL;
}
