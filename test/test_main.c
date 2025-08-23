//
// Created by tilok on 23.08.2025.
//

#include "string.h"
#include <assert.h>
#include <stdio.h>

#include "../string.h"

int test_count_occurrences() {
    const char* test_str = "11abababb111";

    const size_t num_a = str_count_occurrences(test_str, 'a');
    const size_t num_b = str_count_occurrences(test_str, 'b');
    const size_t num_one = str_count_occurrences(test_str, '1');

    assert(num_a == 3);
    assert(num_b == 4);
    assert(num_one == 5);

    return 0;
}


int test_count_occurrences_by_substring() {
    const char* test_str = "Hello, test. test";

    const size_t num_hello = str_count_occurrences_of_substring(test_str, "Hello");
    const size_t num_test = str_count_occurrences_of_substring(test_str, "test");

    assert(num_hello == 1);
    assert(num_test == 2);

    return 0;
}

int test_split_function() {
    char* test_str = "this,is,a,test";
    char** parts = nullptr;
    const size_t size = str_split_by_char(test_str, ',', &parts);
    assert(parts != NULL);

    assert(size == 4);
    assert(strcmp(parts[0], "this") == 0);
    assert(strcmp(parts[1], "is") == 0);
    assert(strcmp(parts[2], "a") == 0);
    assert(strcmp(parts[3], "test") == 0);

    for (int i = 0; i < size; i++) {
        free(parts[i]);
    }
    free(parts);

    return 0;
}


int test_split_function_by_substring() {
    char* test_str = "thissplitissplitasplittest";
    char** parts = nullptr;
    const size_t size = str_split_by_substring(test_str, "split", &parts);
    assert(parts != NULL);

    printf("size: %llu\n", size);

    assert(size == 4);
    assert(strcmp(parts[0], "this") == 0);
    assert(strcmp(parts[1], "is") == 0);
    assert(strcmp(parts[2], "a") == 0);
    assert(strcmp(parts[3], "test") == 0);

    for (int i = 0; i < size; i++) {
        free(parts[i]);
    }
    free(parts);

    return 0;
}

int test_string_to_upper() {
    char test_str[] = "Hello, test. test";
    str_to_upper(test_str);
    assert(strcmp(test_str, "HELLO, TEST. TEST") == 0);

    return 0;
}

int test_string_to_lower() {
    char test_str[] = "Hello, test. test";
    str_to_lower(test_str);
    assert(strcmp(test_str, "hello, test. test") == 0);

    return 0;
}

int test_string_functions() {
    int result = 0;

    result += test_split_function();
    result += test_count_occurrences();
    result += test_count_occurrences_by_substring();
    result += test_split_function_by_substring();
    result += test_string_to_upper();
    result += test_string_to_lower();

    return result;
}

int main() {
    return test_string_functions();
}