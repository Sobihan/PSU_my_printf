/*
** EPITECH PROJECT, 2018
** switches
** File description:
** switches
*/

#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);
void my_putstr(char *str);
int my_putnbr(int nb);
char *convertisation(va_list list, int b, int min_or_cap);

void switches(char *flags,int i, va_list list)
{
    int base;
    char *str;

    switch (flags[i]) {
    case 'd':
    case 'i':
        my_putnbr(va_arg(list, int));
        break;
    case 's':
        str = va_arg(list, char *);
        if (str == NULL)
            my_putstr("null");
        else
            my_putstr(str);
        break;
    case '%':
        my_putchar('%');
        break;
    default:
        break;
    }
}

void switch_converter_one(char *flags, int i, va_list list)
{
    int base;
    int min_or_cap = 0;

    switch (flags[i]) {
    case 'b':
        base = 2;
        my_putstr(convertisation(list, base, min_or_cap));
        break;
    case 'o':
        base = 8;
        my_putstr(convertisation(list, base, min_or_cap));
        break;
    case 'c':
        my_putchar(va_arg(list,int));
        break;
    default:
        break;
    }
}

void switch_converter_two(char *flags, int i, va_list list)
{
    int base = 16;
    int min_or_cap;

    switch (flags[i]) {
    case 'x':
        min_or_cap = 39;
        my_putstr(convertisation(list, base, min_or_cap));
        break;
    case 'X':
        min_or_cap = 7;
        my_putstr(convertisation(list, base, min_or_cap));
        break;
    case 'p':
        min_or_cap = 39;
        my_putstr("0x");
        my_putstr(convertisation(list, base, min_or_cap));
        break;
    default:
        break;
    }
}
