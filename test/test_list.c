//
// Created by tilok on 23.08.2025.
//
#include <assert.h>
#include <string.h>

#include "tstd/list.h"

int test_list_create() {
    list* list = list_create();

    assert(list->capacity == 10);

    list_free(list);
    return 0;
}

int test_list_add_element() {
    list* list = list_create();
    list_add_element(list, "Hello");

    assert(list->length == 1);
    assert(strcmp(list->data[0], "Hello") == 0);

    list_free(list);
    return 0;
}

int test_add_multiple_elements() {
    list* list = list_create();
    for (int i = 0; i < 1000; i++) {
        list_add_element(list, "Hello");
    }
    assert(list->length == 1000);
    assert(list->capacity > 1000);

    list_free(list);
    return 0;
}

int test_delete_element() {
    list* list = list_create();
    list_add_element(list, "Hello");
    list_add_element(list, "World");
    list_add_element(list, "Test");
    list_delete_element(list, 1);

    assert(list->length == 2);
    assert(strcmp(list->data[1], "Test") == 0);

    return 0;
}

int main() {
    int result = 0;

    result += test_list_create();
    result += test_list_add_element();
    result += test_add_multiple_elements();
    result += test_delete_element();

    return result;
}