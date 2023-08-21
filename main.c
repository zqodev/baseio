#include "string.h"
#include "utils.h"
#include "stdio.h"

int main(void)
{
    void *ptr = (void *)0x12345678;

    printf("Character: %c\n", 'A');
    printf("String: %s\n", "Hello, world!");
    printf("Integer (decimal): %d\n", 12345);
    printf("Unsigned Integer (decimal): %u\n", 67890);
    printf("Hexadecimal decimal (lowercase): %x\n", 255);
    printf("Hexadecimal decimal (uppercase): %X\n", 145);
    printf("Hexadecimal float (lowercase): %a\n", 123.456);
    printf("Hexadecimal float (uppercase): %A\n", 140.247);
    printf("Octal: %o\n", 255);
    printf("Signed Long: %l\n", -1234567890);
    printf("Unsigned Long: %L\n", 987543210);
    printf("Signed long long: %g\n", -123456789012345);
    printf("Unsigned long long: %G\n", 987654321012345);
    printf("Signed short: %h\n", -123);
    printf("Unsigned short: %H\n", 456);
    printf("Float value: %f\n", 3.14159);
    printf("Scientific notation: %e\n", 12345.6789);
    printf("This is a %% character.\n");
    printf("Pointer value: %p\n", ptr);

    return 0;
}