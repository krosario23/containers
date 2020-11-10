#include <stdio.h>

#include "containers.h"

bool valid_type(data_t type) {
    bool valid = false;

    switch (type) {
        case INT:
        case DOUBLE:
        case CHAR:
        case STRING:
        case PAIR:
        case BOOL:
            valid = true;
    }

    return valid;
}

void print_value(void * val, data_t type) {
    if (!valid_type(type)) {
        printf("unrecognized type\n");
        return;
    }

    switch (type) {
        case INT: {
            printf("%d", *((int *)(val)));
            break;
        }
        case DOUBLE: {
            printf("%f", *((double *)(val)));
            break;
        }
        case CHAR: {
            printf("%c", *((char *)(val)));
            break;
        }
        case STRING: {
            printf("%s", *((const char **)(val)));
            break;
        }
        case PAIR: {
            print_pair(val);
            break;
        }
        case BOOL: {
            printf("%s", *((bool *)(val)) ? "true" : "false");
            break;
        }
        default: {
            printf("unrecognized type\n");
            return;
        }
    }
}
