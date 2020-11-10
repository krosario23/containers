#include <stdbool.h>
#include <stdlib.h>

typedef enum {
    INT,
    DOUBLE,
    CHAR,
    STRING,
    PAIR,
    BOOL,
} data_t;

bool valid_type(data_t type);
void print_value(void * val, data_t type);

// node/list

typedef struct node_t {
    data_t type;
    void * data;
    struct node_t * next;
} node;

node *  new_node(void * new_data, data_t new_type);

bool    insert_head(node ** head, void * new_data, data_t new_type);

bool    delete(node ** head, size_t index);

node *  get_node(node * head, size_t index);

void    print_list(node * head);

void    free_list(node ** head);

// pair

typedef struct pair_t {
    void * key;
    data_t key_t;

    void * val;
    data_t val_t;

} pair;

pair *  new_pair(void * new_key, data_t key_t,
                 void * new_value, data_t value_t);

void    print_pair(pair * p);
