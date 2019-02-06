/*
** EPITECH PROJECT, 2018
** print
** File description:
** functions print
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int my_putnbr(int nb)
{
    int j = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    while ((nb / j) >= 10)
        j = j * 10;
    while (j > 0) {
        my_putchar((nb / j) % 10 + '0');
        j = j / 10;
    }
    return (nb);
}
