/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** Inverse le string
*/

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    char tmp;

    while (str[a] != '\0') {
        a = a + 1;
    }
    a = a - 1;
    while (a >= b) {
        tmp = str[b];
        str[b] = str[a];
        str[a] = tmp;
        a = a - 1;
        b = b + 1;
    }
    return (str);
}
