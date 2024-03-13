#ifndef DYNAMICARRAYLIST_H
#define DYNAMICARRAYLIST_H

typedef struct arraylist {
    int *array;
    int size;
    int capacity;
} arraylist;

void initialize_arraylist(arraylist *list);
arraylist *new_arraylist(void);
void insert(arraylist *list, int element);
int get(arraylist *list, int index);
int indexOf(arraylist *list, int element);
void removeByIndex(arraylist *list, int index);
int size(arraylist *list);
void print_arraylist(const arraylist *list);
void free_arraylist(arraylist *list);

#endif