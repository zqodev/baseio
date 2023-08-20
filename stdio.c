#include <stdarg.h>
#include <unistd.h>

void putchar(char c)
{
    write(1, &c, 1);
}

/*
 * PRINTS
 */

void print_signed_int(int num)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    if (num < 0) {
        putchar('-');
        num = -num;
    }

    char digits[10];
    int index = 0;

    while (num > 0) {
        digits[index] = '0' + (num % 10);
        num /= 10;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(digits[index]);
    }
}

void print_unsigned_int(unsigned int num)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    char digits[10];
    int index = 0;

    while (num > 0) {
        digits[index] = '0' + (num % 10);
        num /= 10;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(digits[index]);
    }
}

void print_signed_long(long num)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    if (num < 0) {
        putchar('-');
        num = -num;
    }

    char digits[20];
    int index = 0;

    while (num > 0) {
        digits[index] = '0' + (num % 10);
        num /= 10;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(digits[index]);
    }
}

void print_unsigned_long(unsigned long num)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    char digits[20];
    int index = 0;

    while (num > 0) {
        digits[index] = '0' + (num % 10);
        num /= 10;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(digits[index]);
    }
}

void print_float(double num) {
    if (num == 0) {
        putchar('0');
        return;
    }

    if (num < 0) {
        putchar('-');
        num = -num;
    }

    int int_part = (int)num;
    double frac_part = num - int_part;

    char int_digits[20];
    int index = 0;

    while (int_part > 0) {
        int_digits[index] = '0' + (int_part % 10);
        int_part /= 10;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(int_digits[index]);
    }
    if (frac_part > 0) {
        putchar('.');
        int frac_index;
        for (frac_index = 0; frac_index < 6; frac_index++) {
            frac_part *= 10;
            int digit = (int)frac_part;
            putchar('0' + digit);
            frac_part -= digit;
        }
    }
}

void print_float_scientific(double num)
{
    if (num < 0) {
        putchar('-');
        num = -num;
    }

    int exponent = 0;

    if (num > 0) {
        while (num >= 10.0) {
            num /= 10.0;
            exponent++;
        }
        while (num < 1.0) {
            num *= 10.0;
            exponent--;
        }
    }

    int significand = (int)num;
    putchar('0' + significand);
    putchar('.');
    int frac_digits = 6;
    while (frac_digits > 0) {
        num -= significand;
        num *= 10.0;
        significand = (int)num;
        putchar('0' + significand);
        frac_digits--;
    }

    putchar('e');
    if (exponent >= 0) {
        putchar('+');
    } else {
        putchar('-');
        exponent = -exponent;
    }

    print_signed_int(exponent);
}

void print_hex(unsigned int num, int uppercase)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    char hex_digits_upper[] = "0123456789ABCDEF";
    char hex_digits_lower[] = "0123456789abcdef";
    char* hex_digits = uppercase ? hex_digits_upper : hex_digits_lower;
    char hex_string[10];
    int index = 0;

    while (num > 0) {
        hex_string[index] = hex_digits[num % 16];
        num /= 16;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(hex_string[index]);
    }
}

void print_octal(unsigned int num)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    char octal_string[12];
    int index = 0;

    while (num > 0) {
        octal_string[index] = '0' + (num % 8);
        num /= 8;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(octal_string[index]);
    }
}

/*
 * MAIN
 */

void printf(char* format, ...)
{
    va_list args;
    va_start(args, format);
    char* p_format = format;

    while (*p_format != '\0') {
        if (*p_format != '%') {
            putchar(*p_format);
            p_format++;
            continue;
        }
        p_format++;
        switch (*p_format) {
            case '%': {
                putchar('%');
                break;
            }
            case 'c': {
                char ch = va_arg(args, int);
                putchar(ch);
                break;
            }
            case 's': {
                char* str = va_arg(args, char*);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                }
                break;
            }
            case 'd': {
                int num = va_arg(args, int);
                print_signed_int(num);
                break;
            }
            case 'u': {
                unsigned int num = va_arg(args, unsigned int);
                print_unsigned_int(num);
                break;
            }
            case 'x': {
                unsigned int num = va_arg(args, unsigned int);
                print_hex(num, 0);
                break;
            }
            case 'X': {
                unsigned int num = va_arg(args, unsigned int);
                print_hex(num, 1);
                break;
            }
            case 'o': {
                unsigned int num = va_arg(args, unsigned int);
                print_octal(num);
                break;
            }
            case 'l': {
                p_format++;
                switch (*p_format) {
                    case 'd': {
                        long num = va_arg(args, long);
                        print_signed_long(num);
                        break;
                    }
                    case 'u': {
                        unsigned long num = va_arg(args, long);
                        print_unsigned_long(num);
                        break;
                    }
                    default:
                        putchar('%');
                        putchar('l');
                        putchar(*p_format);
                        break;
                }
                break;
            }
            case 'f': {
                double num = va_arg(args, double);
                print_float(num);
                break;
            }
            case 'e': {
                double num = va_arg(args, double);
                print_float_scientific(num);
                break;
            }
            default: {
                putchar('%');
                putchar(*p_format);
                break;
            }
        }
        p_format++;
    }
    va_end(args);
}

/**
* %d : Entier signé.
* %u : Entier non signé.
* %ld : Long entier signé.
* %lu : Long entier non signé.
* %f : Nombre à virgule flottante en notation décimale.
* %e : Nombre à virgule flottante en notation scientifique.
* %s : Chaîne de caractères.
* %c : Caractère.
* %x : Entier non signé en hexadécimal (lettres en minuscules).
* %X : Entier non signé en hexadécimal (lettres en majuscules).
* %o : Entier non signé en octal.
* %% : Caractère '%' littéral.
 */