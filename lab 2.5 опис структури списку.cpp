#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <stddef.h>

typedef struct Node {
    float data;
    struct Node *next;
} Node;

/* Відкрита підпрограма: перевірка на нерівність нулю вказівника на наступний елемент */
static inline int has_next(const Node *current) {
    return current != NULL && current->next != NULL;
}

#endif
