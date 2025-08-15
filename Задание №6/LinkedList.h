#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

// Узел связного списка
typedef struct Node {
    void *data;		// Указатель на данные
    struct Node *next;	// Указатель на следующий узел
    size_t sizeofData;	// Размер данных в узле
} Node;

// Связный списка
typedef struct LinkedList {
    Node *head;		// Указатель на первый узел
    size_t data_size;	// Размер данных в узле
    size_t size;	// Количество узлов в списке
} LinkedList;

// Создание нового связного списка
LinkedList* create_list(size_t data_size);

// Добавление элемента в конец списка
void append(LinkedList *list, void *data);

// Получение указателя на данные в узле
void* get_node_data(Node *node);

// Удаление узла из списка
void delete_node(LinkedList *list, Node *node);

// Поиск значения в списке
Node* linear_search(LinkedList *list, void *value, int (*compare)(void *, void *));

// Получение размера списка
size_t get_list_size(LinkedList *list);

// Получение указателя на первый элемент списка
Node* get_first_node(LinkedList *list);

// Вывод элементов списка
void print_list(LinkedList *list, void (*print_func)(void *));

// Освобождение памяти списка
void free_list(LinkedList *list);

// Вывод целого числа
void print_int(void *data);

#endif // LINKED_LIST_H


