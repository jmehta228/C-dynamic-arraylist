#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

// header files here
#include "dynamic_arraylist.c"

int main(void) {
    arraylist *list = new_arraylist();
    for (int i = 1; i < 51; i++) {
        insert(list, i);
    }

    for (int i = 0; i < size(list); i++) {
        if (get(list, i) % 2 != 0) {
            removeByIndex(list, i);
        }
    }
    assert(list->size == 25);
}