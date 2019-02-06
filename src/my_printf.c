/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** printf
*/

#include <stdarg.h>
#include <stdio.h>

void my_putchar(char c);
void switches(char *flags,int i, va_list list);
void switch_converter_one(char *flags, int i, va_list list);
void switch_converter_two(char *flags, int i, va_list list);

int my_printf(char *flags, ...)
{
    int i = 0;
    va_list list;

    va_start(list, flags);
    while (flags[i] != '\0') {
        if (flags[i] == '%') {
            i  = i + 1;
            switches(flags, i, list);
            switch_converter_one(flags, i, list);
            switch_converter_two(flags, i, list);
        } else
            my_putchar(flags[i]);
        i = i + 1;
    }
    va_end(list);
    return (0);
}
