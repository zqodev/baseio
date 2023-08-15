#include <stddef.h>

/**
 * Concatenates the string src to the end of dest.
 * @param dest Destination for concatenation
 * @param src The string to be appended to dest
 */
void strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *(dest++) = *(src++);
    }

    *dest = '\0';
}

/**
 * Concatenates at most n characters from src to the end of dest.
 * @param dest Destination for concatenation
 * @param src The string to be appended to dest
 * @param n The maximum number of characters to concatenate
 */
void strncat(char *dest, const char *src, size_t n) {
    while (*dest != '\0') {
        dest++;
    }

    while (n > 0 && *src != '\0') {
        *(dest++) = *(src++);
        n--;
    }

    *dest = '\0';
}

/**
 * Searches for the first occurrence of character cha in str.
 * @param str The string in which to search
 * @param cha The character to search for
 * @return A pointer to the first occurrence of cha in str, or NULL if not found
 */
const char* strchr(const char *str, int cha) {
    while (*str != '\0' && *str != cha) {
        str++;
    }

    return (*str == cha) ? str : NULL;
}

/**
 * Searches for the last occurrence of character cha in str.
 * @param str The string in which to search
 * @param cha The character to search for
 * @return A pointer to the last occurrence of cha in str, or NULL if not found
 */
const char* strrchr(const char *str, int cha) {
    const char *last_occurrence = NULL;

    while (*str != '\0') {
        if (*str == cha) {
            last_occurrence = str;
        }
        str++;
    }

    if (cha == '\0') {
        return str;
    }

    return last_occurrence;
}

/**
 * Compares strings s1 and s2.
 * @param str1 The first string to compare
 * @param str2 The second string to compare
 * @return 0 if the strings are equal, a negative number if str1 < str2, a positive number if str1 > str2
 */
int strcmp(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0;
    }

    return (*str1 < *str2) ? -1 : 1;
}

/**
 * Compares the first n characters of s1 and s2.
 * @param str1 The first string to compare
 * @param str2 The second string to compare
 * @param n The number of characters to compare
 * @return 0 if the strings are equal, a negative number if str1 < str2, a positive number if str1 > str2
 */
int strncmp(const char* str1, const char* str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    while (n > 0) {
        if (*str1 != *str2) {
            return (*str1 < *str2) ? -1 : 1;
        }

        if (*str1 == '\0') {
            return 0;
        }

        str1++;
        str2++;
        n--;
    }

    return 0;
}

/**
 * Copies string src into dest, including the null-terminating character.
 * @param dest The destination array
 * @param src The source string to copy
 */
void strcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return;
    }

    while (*src != '\0') {
        *(dest++) = *(src++);
    }

    *dest = '\0';
}

/**
 * Copies at most n characters from src into dest.
 * @param dest The destination array
 * @param src The source string to copy
 * @param n The maximum number of characters to copy
 */
void strncpy(char* dest, const char* src, size_t n) {
    if (dest == NULL || src == NULL) {
        return;
    }

    while (n > 0 && *src != '\0') {
        *dest = *src;

        dest++;
        src++;
        n--;
    }

    *dest = '\0';
}

/**
 * Returns the length of string str.
 * @param str The string whose length should be calculated
 * @return The length of the string
 */
size_t strlen(const char *str) {
    const char *end = str;

    while (*end) {
        end++;
    }

    return end - str;
}

/**
 * Compares the first n bytes of memory areas str1 and str2.
 * @param str1 The first memory block to compare
 * @param str2 The second memory block to compare
 * @param n The number of bytes to compare
 * @return 0 if the memory blocks are equal, a negative number if str1 < str2, a positive number if str1 > str2
 */
int memcmp(const void* str1, const void* str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return 0;
    }

    const unsigned char *p1 = str1;
    const unsigned char *p2 = str2;

    for (size_t i = 0; i < n; i++) {
        int diff = p1[i] - p2[i];
        if (diff != 0) {
            return (diff < 0) ? -1 : 1;
        }
    }

    return 0;
}

/**
 * Copies n bytes from the memory area src to the memory area dest.
 * @param dest The destination memory block
 * @param src The source memory block
 * @param n The number of bytes to copy
 * @return A pointer to dest
 */
void* memcpy(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) {
        return NULL;
    }

    unsigned char *p_dest = dest;
    const unsigned char *p_src = src;

    while (n--) {
        *p_dest++ = *p_src++;
    }

    return dest;
}

/**
 * Copies n bytes from the memory area src to the memory area dest (areas may overlap).
 * @param dest The destination memory block
 * @param src The source memory block
 * @param n The number of bytes to copy
 * @return A pointer to dest
 */
void* memmove(void *dest, const void *src, size_t n) {
    if (dest == NULL || src == NULL || n == 0) {
        return NULL;
    }

    unsigned char *p_dest = dest;
    const unsigned char *p_src = src;

    if (p_dest <= p_src || p_dest >= p_src + n) {
        while (n--) {
            *p_dest++ = *p_src++;
        }
    } else {
        p_dest += n - 1;
        p_src += n - 1;

        while (n--) {
            *p_dest-- = *p_src--;
        }
    }

    return dest;
}