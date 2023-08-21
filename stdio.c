#include <stdarg.h>
#include <unistd.h>

void putchar(char c)
{
    write(1, &c, 1);
}

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

void print_octal_unsigned_long(unsigned long num)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    char digits[22];
    int index = 0;

    while (num > 0) {
        digits[index] = '0' + (num % 8);
        num /= 8;
        index++;
    }
    while (index > 0) {
        index--;
        putchar(digits[index]);
    }
}

void print_signed_long_long(long long num)
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

void print_unsigned_long_long(unsigned long long num)
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

void print_float(double num, int precision) {
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
    if (precision > 0) {
        putchar('.');
        for (int frac_index = 0; frac_index < precision; frac_index++) {
            frac_part *= 10;
            int digit = (int)frac_part;
            putchar('0' + digit);
            frac_part -= digit;
        }
    } else if (precision == 0) {
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
}

void print_float_scientific(double num, int precision)
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

    if (precision > 0) {
        for (int frac_index = 0; frac_index < precision; frac_index++) {
            num -= significand;
            num *= 10.0;
            significand = (int)num;
            putchar('0' + significand);
        }

        putchar('e');
        if (exponent >= 0) {
            putchar('+');
        } else {
            putchar('-');
            exponent = -exponent;
        }
    } else if (precision == 0) {
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
    }

    print_signed_int(exponent);
}


void print_signed_short(int num)
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

void print_unsigned_short(unsigned int num)
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

void print_float_hex(double num, int uppercase)
{
    if (num == 0) {
        putchar('0');
        return;
    }

    unsigned long long int_bits = *(unsigned long long *)&num;

    char hex_digits_upper[] = "0123456789ABCDEF";
    char hex_digits_lower[] = "0123456789abcdef";
    char* hex_digits = uppercase ? hex_digits_upper : hex_digits_lower;
    char hex_string[20];
    int index = 0;

    while (int_bits > 0) {
        hex_string[index] = hex_digits[int_bits % 16];
        int_bits /= 16;
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

void print_pointer(void* ptr)
{
    uintptr_t ptr_value = (uintptr_t)ptr;
    int num_hex_digits = sizeof(ptr_value) * 2;
    char hex_digits[] = "0123456789abcdef";
    int start_printing = 0;

    putchar('0');
    putchar('x');
    for (int i = num_hex_digits - 1; i >= 0; i--) {
        int digit = (ptr_value >> (i * 4)) & 0xF;
        if (digit != 0 || start_printing) {
            start_printing = 1;
            putchar(hex_digits[digit]);
        }
    }
    if (start_printing == 0) {
        putchar('0');
    }
}

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
        if (*p_format != '%') {
            switch (*p_format) {
                case 'c': {
                    putchar(va_arg(args, int));
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
                    print_signed_int(va_arg(args, int));
                    break;
                }
                case 'u': {
                    print_unsigned_int(va_arg(args, unsigned int));
                    break;
                }
                case 'x': {
                    print_hex(va_arg(args, unsigned int), 0);
                    break;
                }
                case 'X': {
                    print_hex(va_arg(args, unsigned int), 1);
                    break;
                }
                case 'a': {
                    print_float_hex(va_arg(args, double), 0);
                    break;
                }
                case 'A': {
                    print_float_hex(va_arg(args, double), 1);
                }
                case 'o': {
                    print_octal(va_arg(args, unsigned int));
                    break;
                }
                case 'l': {
                    p_format++;
                    switch (*p_format) {
                        case 'd': {
                            print_signed_long(va_arg(args, long));
                            break;
                        }
                        case 'u': {
                            print_unsigned_long(va_arg(args, unsigned long));
                            break;
                        }
                        case 'o': {
                            print_octal_unsigned_long(va_arg(args, unsigned long));
                            break;
                        }
                        case 'l': {
                            p_format++;
                            switch (*p_format) {
                                case 'd': {
                                    print_signed_long_long(va_arg(args, long long));
                                    break;
                                }
                                case 'u': {
                                    print_unsigned_long_long(va_arg(args, unsigned long long));
                                    break;
                                }
                                default:
                                    putchar('%');
                                    putchar('l');
                                    putchar('l');
                                    putchar(*p_format);
                                    break;
                            }
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
                case 'h': {
                    p_format++;
                    switch (*p_format) {
                        case 'd': {
                            print_signed_short(va_arg(args, int));
                            break;
                        }
                        case 'u': {
                            print_unsigned_short(va_arg(args, unsigned int));
                            break;
                        }
                    }
                }
                case 'f': {
                    print_float(va_arg(args, double), 0);
                    break;
                }
                case 'e': {
                    print_float_scientific(va_arg(args, double), 0);
                    break;
                }
                case 'p': {
                    print_pointer(va_arg(args, void*));
                    break;
                }
                case '.': {
                    p_format++;
                    int precision = 0;
                    while (*p_format >= '0' && *p_format <= '9') {
                        precision = precision * 10 + (*p_format - '0');
                        p_format++;
                    }
                    switch (*p_format) {
                        case 'f': {
                            print_float(va_arg(args, double), precision);
                            break;
                        }
                        case 'e': {
                            print_float_scientific(va_arg(args, double), precision);
                            break;
                        }
                        default: {
                            putchar('%');
                            putchar('.');
                            putchar(*p_format);
                            break;
                        }
                    }
                    break;
                }
                default: {
                    putchar('%');
                    putchar(*p_format);
                    break;
                }
            }
        } else {
            putchar('%');
        }
        p_format++;
    }
    va_end(args);
}

/**
%d : Entier signé.
%u : Entier non signé.
%ld : Long entier signé.
%lu : Long entier non signé.
%lo : Entier non signé en long en octal
TODO %lx : Entier long non signé en hexadécimal
TODO %lX : Entier long non signé en hexadécimal (majuscules)
TODO %Lf : Nombre à virgule flottante en double
TODO %Le : Nombre à virgule flottante en double en notation scientifique (exponentielle, minuscules)
TODO %LE : Nombre à virgule flottante en double en notation scientifique (exponentielle, majuscules)
TODO %La : Nombre à virgule flottante en double en notation hexadécimale (minuscules)
TODO %LA : Nombre à virgule flottante en double en notation hexadécimale (majuscules)
%lld : Long long entier signé.
%llu : Long long entier non signé.
TODO %llo : Entier non signé en long long en octal
TODO %llx : Entier long long non signé en hexadécimal
TODO %llX : Entier long long non signé en hexadécimal (majuscules)
%hd : Short entier signé.
%hu : Short entier non signé.
TODO %ho : Entier non signé en short en octal
TODO %hx : Entier court (short) non signé en hexadécimal
TODO %hX : Entier court (short) non signé en hexadécimal (majuscules)
TODO %hhd : Entier signé en char
TODO %hhu : Entier non signé en char
TODO %hho : Entier non signé en char en octal
TODO %hhx : Entier non signé en char en hexadécimal (lettres minuscules)
TODO %hhX : Entier non signé en char en hexadécimal (lettres majuscules)
%o : Entier non signé en octal.
%x : Entier non signé en hexadécimal (lettres en minuscules).
%X : Entier non signé en hexadécimal (lettres en majuscules).
%f : Nombre à virgule flottante en notation décimale.
%e : Nombre à virgule flottante en notation scientifique.
%a : Nombre à virgule flottante en notation hexadécimale.
%A : Nombre à virgule flottante en notation hexadécimale (majuscules pour l'exposant).
%c : Caractère.
%s : Chaîne de caractères.
%p : Pointeur.
%% : Caractère '%' littéral.
TODO %n : Nombre d'octets écrits jusqu'à ce point est stocké dans l'argument correspondant
*/