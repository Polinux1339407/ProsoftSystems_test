#include <stdio.h>
#include "LinkedList.h"

//Имеем чистый С. Напишите reusable API для работы со связным списком структур.
//Структуры могу быть разного типа, но в одном списке будут структуры одного типа.
//Приведите пример использования вашего API.

// Пример функции сравнения для целых чисел
int compare_int(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {

    LinkedList *list = create_list(sizeof(int));

    for (int i = 0; i < 5; i++) {
        append(list, &i);
    }

    printf("Elements in the list: ");
    print_list(list, print_int);
    printf("\n");
    printf("Size of the list: %zu\n", get_list_size(list));

    // Линейный поиск значения в списке
    int search_value = 3;
    Node *found_node = linear_search(list, &search_value, compare_int);

    if (found_node) {
        printf("Found value: %d\n", *(int *)get_node_data(found_node));
    } else {
        printf("Value not found.\n");
    }
    // Получение первого элемента списка и его вывод
    Node *first_node = get_first_node(list);
    if (first_node) {
        printf("First element: %d\n", *(int *)get_node_data(first_node));
    } else {
        printf("The list is empty.\n");
    }
    free_list(list);
    return 0;
}
