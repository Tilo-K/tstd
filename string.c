#include  "tstd/string.h"

size_t str_count_occurrences(const char* str, const char c) {
    size_t i = 0;
    size_t count = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            count++;
        }
        i++;
    }

    return count;
}

size_t str_count_occurrences_of_substring(const char* str, const char* substr) {
    size_t i = 0;
    size_t count = 0;
    while (str[i] != '\0') {
        if (strstr(&str[i], substr) == &str[i]) {
            count++;
        }
        i++;
    }
    return count;
}

size_t str_split_by_char(const char* str, const char delimiter, char*** result) {
    const size_t size = str_count_occurrences(str, delimiter);
    char** parts = malloc((size+1) * sizeof(char*));
    int curr_part_idx = 0;
    int last_part_end = 0;
    int idx = 0;
    while (str[idx] != '\0') {
        if (str[idx] == delimiter) {
            const int len = idx - last_part_end;
            char* part = malloc(sizeof(char) * (len+1));
            memcpy(part, &str[last_part_end], len);
            part[idx-last_part_end] = '\0';

            parts[curr_part_idx++] = part;
            last_part_end = idx;
            last_part_end++;
        }
        idx++;
    }
    char* part = malloc(sizeof(char) * (idx-last_part_end+1));
    memcpy(part, &str[last_part_end], idx-last_part_end);
    part[idx-last_part_end] = '\0';
    parts[curr_part_idx++] = part;

    *result = parts;
    return curr_part_idx;
}

size_t str_split_by_substring(const char* str, const char* substr, char*** result) {
    const size_t size = str_count_occurrences_of_substring(str, substr);
    char** parts = malloc((size+1) * sizeof(char*));
    size_t curr_part_idx = 0;
    size_t last_part_end = 0;
    size_t idx = 0;

    while (str[idx] != '\0') {
        if (strstr(&str[idx], substr) == &str[idx]) {
            const size_t len = idx - last_part_end;
            char* part = malloc(sizeof(char) * (len+1));
            memcpy(part, &str[last_part_end], len);
            part[len] = '\0';

            parts[curr_part_idx++] = part;
            last_part_end = idx;
            last_part_end += strlen(substr);
        }
        idx++;
    }
    const size_t len = idx - last_part_end;
    char* part = malloc(sizeof(char) * (len+1));
    memcpy(part, &str[last_part_end], len);
    part[len] = '\0';

    parts[curr_part_idx++] = part;

    *result = parts;
    return curr_part_idx;
}

void str_to_upper(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
    }
}

void str_to_lower(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';
        }
    }
}

char* str_concat(const char* str1, const char* str2) {
    const size_t len1 = strlen(str1);
    const size_t len2 = strlen(str2);

    char* result = malloc(sizeof(char) * (len1 + len2 + 1));
    memcpy(result, str1, len1);
    memcpy(&result[len1], str2, len2);
    result[len1 + len2] = '\0';
    return result;
}

bool p_str_char_is_rubbish(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char* str_trim(const char* str) {
    size_t start = 0;
    size_t end = strlen(str) - 1;
    while (p_str_char_is_rubbish(str[start])) {
        start++;
    }
    while (p_str_char_is_rubbish(str[end])) {
        end--;
    }

    char* new_str = malloc(sizeof(char) * (end - start + 2));
    memcpy(new_str, &str[start], end - start + 1);
    new_str[end-start+1] = '\0';

    return new_str;
}