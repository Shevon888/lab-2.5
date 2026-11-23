#include <stdio.h>
#include <stdlib.h>
#include "list_utils.h"


void append_node(Node **head, float value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while (has_next(curr)) {
        curr = curr->next;
    }
    curr->next = new_node;
}

Node *build_odd_positions_list(const Node *first_head) {
    Node *second_head = NULL;
    const Node *curr = first_head;
    int pos = 1; 

    while (curr != NULL) {
        if (pos % 2 != 0) {
            append_node(&second_head, curr->data);
        }
        if (has_next(curr)) {
            curr = curr->next;
            pos++;
        } else {
            break;
        }
    }

    return second_head;
}

void print_list(const Node *head) {
    const Node *curr = head;
    while (curr != NULL) {
        printf("%.1f -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void free_list(Node **head) {
    Node *curr = *head;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int main(void) {
    Node *list1 = NULL;
    float values[9] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f};

    for (int i = 0; i < 9; i++) {
        append_node(&list1, values[i]);
    }

    printf("Перший список (9 елементів):\n");
    print_list(list1);

    Node *list2 = build_odd_positions_list(list1);

    printf("\nДругий список (непарні позиції 1-го списку):\n");
    print_list(list2);

    free_list(&list1);
    free_list(&list2);

    return 0;
}
