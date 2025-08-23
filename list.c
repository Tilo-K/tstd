//
// Created by tilok on 23.08.2025.
//

#include "tstd/list.h"

#include <string.h>


list* list_create() {
    return list_create_with_capacity(10);
}

list* list_create_with_capacity(size_t capacity) {
    void** data = malloc(capacity * sizeof(void *));
    list* new_list = malloc(sizeof(list));

    new_list->data = data;
    new_list->length = 0;
    new_list->capacity = capacity;

    return new_list;
}

void list_resize(list* list) {
    size_t new_capacity = (list->capacity + 1) * 1.5;
    void** new_data = malloc(new_capacity * sizeof(void *));
    memcpy(new_data, list->data, list->length * sizeof(void *));
    free(list->data);
    list->data = new_data;
    list->capacity = new_capacity;
}

void list_add_element(list* list, void* element) {
    if (list->length == list->capacity) {
        list_resize(list);
    }

    list->data[list->length++] = element;
}

void list_free(list* list) {
    free(list->data);
    free(list);
}

void list_free_elements(list* list) {
    for (int i = 0; i < list->length; i++) {
        free(list->data[i]);
    }
    free(list->data);
    free(list);
}

void* list_delete_element(list* list, int index) {
    void* element = list->data[index];
    list->length--;
    for (int i = index; i < list->length; i++) {
        list->data[i] = list->data[i + 1];
    }
    return element;
}