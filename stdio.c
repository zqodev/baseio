#include <stdarg.h>
#include <unistd.h>

#define SHORT_MAX 32767
#define SHORT_MIN (-32768)
#define USHORT_MAX 65535
#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-LLONG_MAX - 1)
#define ULLONG_MAX 18446744073709551615ULL

typedef struct {
    char identifier;
    void (*print_function)(va_list args);
} Formatter;

void putchar(char c)
{
    write(1, &c, 1);
}

/*
 * PRINTS
 */

void print_character(va_list args)
{
    char ch = va_arg(args, int);
    putchar(ch);
}

void print_string(va_list args)
{
    char* str = va_arg(args, char*);
    while (*str != '\0') {
        putchar(*str);
        str++;
    }
}

void print_string_direct(char* str)
{
    while (*str != '\0') {
        putchar(*str);
        str++;
    }
}

void print_signed_int(va_list args)
{
    int num = va_arg(args, int);

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

void print_signed_int_direct(int num)
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

void print_unsigned_int(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);

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

void print_signed_long(va_list args)
{
    long num = va_arg(args, long);

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

void print_unsigned_long(va_list args)
{
    long num = va_arg(args, unsigned long);

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

void print_signed_long_long(va_list args)
{
    long long num = va_arg(args, long long);

    if (num > LLONG_MAX || num < LLONG_MIN) {
        print_string_direct("Value out of range for a long long");
        return;
    }

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

void print_unsigned_long_long(va_list args)
{
   unsigned long long num = va_arg(args, unsigned long long);

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


void print_signed_short(va_list args)
{
    int num = va_arg(args, int);

    if (num > SHORT_MAX || num < SHORT_MIN) {
        print_string_direct("Value out of range for a short");
        return;
    }

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

void print_unsigned_short(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);

    if (num > USHORT_MAX) {
        print_string_direct("Value out of range for an unsigned short");
        return;
    }

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

void print_float(va_list args) {
    double num = va_arg(args, double);

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

void print_float_scientific(va_list args)
{
    double num = va_arg(args, double);

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
    print_signed_int_direct(exponent);
}

void print_hex_lower(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);

    if (num == 0) {
        putchar('0');
        return;
    }

    char hex_digits[] = "0123456789abcdef";
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

void print_hex_upper(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);

    if (num == 0) {
        putchar('0');
        return;
    }

    char hex_digits[] = "0123456789ABCDEF";
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

void print_float_hex_lower(va_list args)
{
    double num = va_arg(args, double);

    if (num == 0) {
        putchar('0');
        return;
    }

    unsigned long long int_bits = *(unsigned long long *)&num;

    char hex_digits[] = "0123456789abcdef";
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

void print_float_hex_upper(va_list args)
{
    double num = va_arg(args, double);

    if (num == 0) {
        putchar('0');
        return;
    }

    unsigned long long int_bits = *(unsigned long long *)&num;

    char hex_digits[] = "0123456789ABCDEF";
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

void print_octal(va_list args)
{
    unsigned int num = va_arg(args, int);

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

void print_pointer(va_list args)
{
    void *ptr = va_arg(args, void*);
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

void print_default(va_list args)
{
    putchar('%');
}

Formatter formatters[] = {
    {'c', print_character},
    {'s', print_string},
    {'d', print_signed_int},
    {'u', print_unsigned_int},
    {'l', print_signed_long},
    {'L', print_unsigned_long},
    {'g', print_signed_long_long},
    {'G', print_unsigned_long_long},
    {'h', print_signed_short},
    {'H', print_unsigned_short},
    {'x', print_hex_lower},
    {'X', print_hex_upper},
    {'a', print_float_hex_lower},
    {'A', print_float_hex_upper},
    {'o', print_octal},
    {'f', print_float},
    {'e', print_float_scientific},
    {'p', print_pointer},
    {'%', print_default},
};


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
        char formatter_char = *p_format;
        p_format++;

        int num_formatters = sizeof(formatters) / sizeof(Formatter);
        int found_formatter = -1;
        for (int i = 0; i < num_formatters; i++) {
            if (formatters[i].identifier == formatter_char) {
                found_formatter = i;
                break;
            }
        }

        if (found_formatter != -1) {
            formatters[found_formatter].print_function(args);
        } else {
            putchar('%');
            putchar(formatter_char);
        }
    }
    va_end(args);
}

/**
%d : Entier signé.
%u : Entier non signé.
%l : Long entier signé.
%L : Long entier non signé.
%g : Long long entier signé.
%G : Long long entier non signé.
%h : Short entier signé.
%H : Short entier non signé.
TODO %jd : Intmax_t entier signé.
TODO %ju : Uintmax_t entier non signé.
TODO %zd : size_t entier signé.
TODO %zu : size_t entier non signé.
TODO %td : ptrdiff_t entier signé.
TODO %tu : ptrdiff_t entier non signé.
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
*/