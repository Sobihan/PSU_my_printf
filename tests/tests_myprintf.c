/*
** EPITECH PROJECT, 2018
** test_myprintf
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

char *revstr(char *str);
char *conversation(va_list list, int b, int min_or_cap);
int my_printf(char *flags, ...);
void my_putchar(char c);
void my_putstr(char *str);
int my_putnbr(int nb);
void switches(char *flags, int i, va_list list);
void switch_converter_one(char *flags, int i, va_list list);
void switch_converter_two(char *flags, int i, va_list list);

void redirect_all_std(void)
{
    cr_redirect_stdout() ;
    cr_redirect_stderr() ;
}

Test (my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("Hello World");
    cr_assert_stdout_eq_str("Hello World");
}

Test (my_printf, long_string, .init = redirect_all_std)
{
    my_printf("azertyuiopqsdfghjklmwxcvbn");
    cr_assert_stdout_eq_str("azertyuiopqsdfghjklmwxcvbn");
}

Test (my_printf, digit_simple, .init = redirect_all_std)
{
    my_printf("%d",9);
    cr_assert_stdout_eq_str("9");
}

Test (my_printf, digit_long, .init = redirect_all_std)
{
    my_printf("%d",123456789);
    cr_assert_stdout_eq_str("123456789");
}

Test (my_printf, octet_simple, .init = redirect_all_std)
{
    my_printf("%o",9);
    cr_assert_stdout_eq_str("11");
}

Test (my_printf, o_long, .init = redirect_all_std)
{
    my_printf("%o",987654321);
    cr_assert_stdout_eq_str("7267464261");
}

Test (my_printf, x_simple, .init = redirect_all_std)
{
    my_printf("%x", 20);
    cr_assert_stdout_eq_str("14");
}

Test (my_printf, x_long, .init = redirect_all_std)
{
    my_printf("%x",987654321);
    cr_assert_stdout_eq_str("3ade68b1");
}

Test (my_printf, X_simple, .init = redirect_all_std)
{
    my_printf("%X", 20);
    cr_assert_stdout_eq_str("14");
}

Test (my_printf, X_long, .init = redirect_all_std)
{
    my_printf("%X",987654321);
    cr_assert_stdout_eq_str("3ADE68B1");
}

Test (my_printf, c_simple, .init = redirect_all_std)
{
    my_printf("%c", 'A');
    cr_assert_stdout_eq_str("A");
}

Test (my_printf, s_simple, .init = redirect_all_std)
{
    my_printf("%s","azertyuiop");
    cr_assert_stdout_eq_str("azertyuiop");
}

Test (my_printf, b_simple, .init = redirect_all_std)
{
    my_printf("%b",8);
    cr_assert_stdout_eq_str("1000");
}

Test (my_printf, b_hard, .init = redirect_all_std)
{
    my_printf("%b",987);
    cr_assert_stdout_eq_str("1111011011");
}

Test (my_printf, dd, .init = redirect_all_std)
{
    my_printf("%d%d",987,987);
    cr_assert_stdout_eq_str("987987");
}
