#include <corecrt.h>

int strlen(const char *str);
void strcpy(char* dest, const char* src);
const char* strcat(char *dest, const char *src);
const char* strncat(char *dest, const char *src, size_t n);
const char* strchr(const char *str, int cha);
const char* strrchr(const char *str, int cha);
int strcmp(const char* str1, const char* str2);
int strcasecmp(char * str1, char* str2);
int strncmp(const char* str1, const char* str2, size_t n);
void strncpy(char* dest, const char* src, size_t n);
int memcmp(const void* str1, const void* str2, size_t n);
void memcpy(void *dest, const void *src, size_t n);
void* memmove(void *dest, const void *src, size_t n);
int strncasecmp(char * str1, char* str2, size_t n);