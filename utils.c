#include <stddef.h>

/**
 * Convert all the characters in the string to lowercase.
 * @param str
 */
void lowercase(char *str) {
    if (str == NULL) {
        return;
    }
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str = (*str - 'A') + 'a';
        }
        str++;
    }
}

/**
 * Convert all the characters in the string to uppercase.
 * @param str
 */
void uppercase(char *str) {
    if (str == NULL) {
        return;
    }
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = (*str - 'a') + 'A';
        }
        str++;
    }
}

/**
 * Convert all first characters in the string to uppercase.
 * @param str
 */
void capitalize(char *str) {
    if (str == NULL) {
        return;
    }

    int capitalize_next = 1;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            capitalize_next = 1;
        } else {
            if (capitalize_next && *str >= 'a' && *str <= 'z') {
                *str = (*str - 'a') + 'A';
            }
            capitalize_next = 0;
        }
        str++;
    }
}
