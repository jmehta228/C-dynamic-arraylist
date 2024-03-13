#include <stdio.h>
#include <stdlib.h>
#include "dynamic_arraylist.h"

#define INITIAL_CAPACITY 10

void initialize_arraylist(arraylist *list) {
	list->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
	list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

arraylist *new_arraylist(void) { // empty list
	arraylist *list = (arraylist *)malloc(sizeof(arraylist));
	if (list == NULL) {
		printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
		
	list->array = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
    return list;
}

void insert(arraylist *list, int element) {
	if (list->size == list->capacity) {
		int newCapacity = list->capacity * 2;
		list->array = (int *)realloc(list->array, newCapacity * sizeof(int));
        if (list->array == NULL) {
			printf("Memory allocation failed.\n");
			exit(EXIT_FAILURE);
		}
        list->capacity = newCapacity;
    }
	list->array[list->size] = element;
	list->size++;
}

int get(arraylist *list, int index) {
	return list->array[index];
}

int indexOf(arraylist *list, int element) {
	for (int i = 0; i < list->size; i++) {
		if (list->array[i] == element) {
			return i;
		}
	}
	return -1;
}

void removeByIndex(arraylist *list, int index) {
	for (int i = index; i < list->size; i++) {
		list->array[i] = list->array[i + 1];
	}
	list->size -= 1;
}

int size(arraylist *list) {
    return list->size;
}

void print_arraylist(const arraylist *list) {
	for (int i = 0; i < list->size; i++) {
		printf("%d\n", list->array[i]);
	}
}

void free_arraylist(arraylist *list) {
	free(list->array);
	list->size = 0;
    list->capacity = 0;
}