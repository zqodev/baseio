#include <stddef.h>

void strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *(dest++) = *(src++);
    }

    *dest = '\0';
}


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

const char* strchr(const char *str, int cha) {
    while (*str != '\0' && *str != cha) {
        str++;
    }

    return (*str == cha) ? str : NULL;
}

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

int strcmp(const char* str1, const char* str2) {
    if (str1 == NULL || str2 == NULL) {
        return -1;
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

int strncmp(const char* str1, const char* str2, size_t n) {
    if (str1 == NULL || str2 == NULL) {
        return -1;
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

void strcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) {
        return;
    }

    while (*src != '\0') {
        *dest = *src;

        dest++;
        src++;
    }

    *dest = '\0';
}

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

size_t strlen(const char *str) {
    const char *end = str;

    while (*end) {
        end++;
    }

    return end - str;
}