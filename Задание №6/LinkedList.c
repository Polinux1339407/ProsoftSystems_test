#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

LinkedList* create_list(size_t data_size) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (!list) return NULL;
    list->head = NULL;
    list->data_size = data_size;
    list->size = 0;
    return list;
}

void append(LinkedList *list, void *data) {
    if (!list || !data) return;

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) return;

    new_node->data = malloc(list->data_size);
    if (!new_node->data) {
        free(new_node);
        return;
    }

    memcpy(new_node->data, data, list->data_size);
    new_node->sizeofData = list->data_size;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    list->size++; // Увеличиваем размер списка
}

void* get_node_data(Node *node) {
    if (!node) return NULL;
    return node->data;
}

void delete_node(LinkedList *list, Node *node) {
    if (!list || !node) return;

    if (list->head == node) {
        list->head = node->next;
    } else {
        Node *current = list->head;
        while (current != NULL && current->next != node) {
            current = current->next;
        }
        if (current != NULL) {
            current->next = node->next;
        }
    }

    free(node->data);
    free(node);
    list->size--;
}

Node* linear_search(LinkedList *list, void *value, int (*compare)(void *, void *)) {
    if (!list || !value || !compare) return NULL;

    Node *current = list->head;
    while (current != NULL) {
        if (compare(current->data, value) == 0) {
            return current; // Найден узел с искомым значением
        }
        current = current->next;
    }

    return NULL; // Узел не найден
}

size_t get_list_size(LinkedList *list) {
    if (!list) return 0;
    return list->size;
}

Node* get_first_node(LinkedList *list) {
    if (!list) return NULL;
    return list->head;
}

void print_list(LinkedList *list, void (*print_func)(void *)) {
    if (!list || !print_func) return;

    Node *current = list->head;
    while (current != NULL) {
        print_func(current->data);
        current = current->next;
    }
}

void free_list(LinkedList *list) {
    if (!list) return;

    Node *current = list->head;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current->data);
        free(current);
        current = next_node;
    }

    free(list);
}

void print_int(void *data) {
    printf("%d ", *(int *)data);
}




