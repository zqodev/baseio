#include "string.h"
#include "utils.h"
#include "stdio.h"

int main(void)
{
    printf("Character: %c\n", 'A');
    printf("String: %s\n", "Hello, world!");
    printf("Integer (decimal): %d\n", 12345);
    printf("Unsigned Integer (decimal): %u\n", 67890);
    printf("Hexadecimal (lowercase): %x\n", 255);
    printf("Hexadecimal (uppercase): %X\n", 255);
    printf("Octal: %o\n", 255);
    printf("Signed Long: %ld\n", -1234567890);
    printf("Unsigned Long: %lu\n", 987543210);
    printf("Float value: %f\n", 3.14159);
    printf("Scientific notation: %e\n", 12345.6789);
    printf("This is a %% character.");

    return 0;
}