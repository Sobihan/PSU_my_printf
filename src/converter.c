/*
** EPITECH PROJECT, 2018
** converter
** File description:
** converter
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char *my_revstr(char *str);

char *convertisation(va_list list, int b, int min_or_cap)
{
    int i = 0;
    int nb = va_arg(list, int);
    char *res = malloc(sizeof(char) * b);

    if (malloc == NULL)
        return (NULL);
    while (nb >= 1) {
        res[i] = nb % b + '0';
        nb = nb / b;
        i = i + 1;
    }
    res[i] = '\0';
    my_revstr(res);
    i = 0;
    while (res[i] != '\0') {
        if (res[i] > '9') {
            res[i] = res[i] + min_or_cap;
        }
        i = i + 1;
    }
    return (res);
}
