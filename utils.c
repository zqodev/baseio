#include <stdio.h>
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
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = (*str - 'a') + 'A';
        }
        str++;
    }
}

/**
 * Convert all first character in the string to uppercase.
 * @param str
 */
void capitalize(char *str) {
    int capitalizeNext = 1;

    while (*str) {
        if (*str == ' ' || *str == '\t' || *str == '\n') {
            capitalizeNext = 1;
        } else {
            if (capitalizeNext && *str >= 'a' && *str <= 'z') {
                *str = (*str - 'a') + 'A';
            }
            capitalizeNext = 0;
        }
        str++;
    }
}