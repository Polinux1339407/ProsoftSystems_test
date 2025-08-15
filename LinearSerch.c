
//Имеем чистый C. Напишите generic функцию линейного поиска в массиве.
//И приведите пример использования вашей функции.

#include <stdio.h>
#include <stdlib.h>

typedef int (*CompareFunc)(const void*, const void*);

// Функция линейного поиска
void* linear_search(void* array, size_t element_size, size_t length, const void* target, CompareFunc compare) {

	if(!array || !target || !compare)
		return NULL;
    for (size_t i = 0; i < length; i++) {
        void* current_element = (char*)array + i * element_size;
        if (compare(current_element, target) == 0) {
            return current_element; // Найден элемент
        }
    }
    return NULL; // Элемент не найден
}

// Функция сравнения двух целых чисел
int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int array[] = {4, 7, 2, 9, 5};
    int target = 2;

    int* result = (int*)linear_search(array, sizeof(int), sizeof(array) / sizeof(array[0]), &target, compare_int);

    if (result != NULL) {
        printf("Element found: %d\n", *result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}

