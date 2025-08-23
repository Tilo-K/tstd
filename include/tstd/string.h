/**
* @file string.h
 * @brief String utilities
 * @date 2025-08-23
 * @author Tilo
 */

#ifndef TSTD_STRING_H
#define TSTD_STRING_H
#include <stdlib.h>
#include <string.h>

/**
 * @brief Count occurrences of a character in a C string.
 * @param str Null-terminated input string (must not be NULL).
 * @param c Character to count.
 * @return Number of times c appears in str.
 */
size_t str_count_occurrences(const char* str, char c);

/**
 * @breif Count the number of times a substring occurs.
 * @param str
 * @param substr The substring to be matches/***
 * @return The number of occurrences
 */
size_t str_count_occurrences_of_substring(const char* str, const char* substr);

/**
 * @brief Split a string by a delimiter.
 *
 * This copies all the parts. You should probably free them after.
 *
 * @param str Input/output string buffer (modified in-place).
 * @param delimiter Delimiter character.
 * @param[out] result On success, set to a malloc'd array of char* tokens.
 * @return Number of tokens on success; 0 if str is empty; (size_t)-1 on error.
 */
size_t str_split_by_char(const char* str,char delimiter, char*** result);

/**
 * @brief Splits a string into parts separated by a given substring.
 *
 * This copies all the parts. You should probably free them after.
 *
 * @param str Null-terminated input string to be split (must not be NULL).
 * @param substr Null-terminated substring used as the delimiter (must not be NULL).
 * @param result Pointer to a dynamically allocated array of null-terminated strings.
 *        The caller is responsible for freeing the allocated memory.
 * @return Number of parts the string has been split into.
 */
size_t str_split_by_substring(const char* str, const char* substr, char*** result);

/**
 * @brief Convert all lowercase letters in a string to uppercase.
 * @param str Null-terminated input string (must not be NULL). The string is modified in place.
 */
void str_to_upper(char* str);

/**
 * @brief Converts all uppercase alphabetic characters in a C string to lowercase.
 * @param str Null-terminated input string to be modified in-place (must not be NULL).
 */
void str_to_lower(char* str);

/**
 * @brief Concatenate two null-terminated strings into a newly allocated string.
 * @param str1 First input string (must not be NULL).
 * @param str2 Second input string (must not be NULL).
 * @return Pointer to a newly allocated null-terminated string containing the concatenated result of str1 and str2.
 *         Caller is responsible for freeing the allocated memory.
 */
char* str_concat(const char* str1, const char* str2);

#endif //TSTD_STRING_H
