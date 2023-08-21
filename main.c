#include "string.h"
#include "utils.h"
#include "stdio.h"

int main(void)
{
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Character: %c\n", 'A');
    printf("String: %s\n", "Hello, world!");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Integer (decimal): %d\n", 12345);
    printf("Unsigned Integer (decimal): %u\n", 67890);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Hexadecimal decimal (lowercase): %x\n", 255);
    printf("Hexadecimal decimal (uppercase): %X\n", 145);
    printf("Hexadecimal float (lowercase): %a\n", 123.456);
    printf("Hexadecimal float (uppercase): %A\n", 140.247);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Octal: %o\n", 255);
    printf("Unsigned Long octal: %lo\n", 987543210);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Signed Long: %ld\n", -1234567890);
    printf("Unsigned Long: %lu\n", 987543210);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Signed long long: %lld\n", -123456789012345);
    printf("Unsigned long long: %llu\n", 987654321012345);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Signed short: %hd\n", -123);
    printf("Unsigned short: %hu\n", 456);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Float value: %f\n", 3.14159);
    printf("Scientific notation: %e\n", 12345.6789);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("This is a %% character.\n");
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Pointer value: %p\n", (void *)0x12345678);
    printf("=-=-=-=-=-=-=-=-=-=\n");
    printf("Coucou, %c || %e || %d || %ld\n", 'c', 12345.6789, 150, -1234567890);
    printf("=-=-=-=-=-=-=-=-=-=\n");

    return 0;
}