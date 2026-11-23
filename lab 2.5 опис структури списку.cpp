#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <stddef.h>

//варіант 2//
typedef struct Node {
    float data;
    struct Node *next;
} Node;

static inline int has_next(const Node *current) {
    return current != NULL && current->next != NULL;
}

#endif
