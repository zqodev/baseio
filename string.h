#include <corecrt.h>

void strcat(char *dest, const char *src);
void strncat(char *dest, const char *src, size_t n);
const char* strchr(const char *str, int cha);
const char* strrchr(const char *str, int cha);
int strcmp(const char* str1, const char* str2);
int strncmp(const char* str1, const char* str2, size_t n);
void strcpy(char* dest, const char* src);
void strncpy(char* dest, const char* src, size_t n);
int strlen(const char *str);