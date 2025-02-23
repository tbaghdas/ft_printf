/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaghdas <tbaghdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:59:53 by tbaghdas          #+#    #+#             */
/*   Updated: 2025/02/23 18:10:55 by tbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parser(va_list args, char c, int *count)
{
	if (c == 'c')
		ft_printchar_fd(va_arg(args, int), 1, count);
	else if (c == 's')
		ft_printstr_fd(va_arg(args, char *), 1, count);
	else if (c == 'p')
		ft_printptr_fd(va_arg(args, void *), 1, count);
	else if (c == 'd')
		ft_printnbr_fd(va_arg(args, int), 1, count);
	else if (c == 'i')
		ft_printnbr_fd(va_arg(args, int), 1, count);
	else if (c == 'u')
		ft_printunbr_fd(va_arg(args, unsigned int), 1, count);
	else if (c == 'x')
		ft_printhex_fd(va_arg(args, unsigned int), 1, count, 32);
	else if (c == 'X')
		ft_printhex_fd(va_arg(args, unsigned int), 1, count, 0);
	else if (c == '%')
		ft_printchar_fd(c, 1, count);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		flag;
	int		count;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	flag = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (flag)
			flag = ft_parser(args, str[i], &count);
		else if (str[i] == '%')
			flag = 1;
		else
			ft_printchar_fd(str[i], 1, &count);
		i++;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
#include <stdarg.h>


int main() {
    int original_ret, custom_ret;

    // Test characters
    char c = 'A';

    original_ret = printf("Original printf: %c\n", c);
    custom_ret = ft_printf("Custom printf: %c\n", c);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test strings
    char *s = "Hello, world!";

    original_ret = printf("Original printf: %s\n", s);
    custom_ret = ft_printf("Custom printf: %s\n", s);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test pointers
    void *p = s;

    original_ret = printf("Original printf: %p\n", p);
    custom_ret = ft_printf("Custom printf: %p\n", p);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test integers
    int d = 123;

    original_ret = printf("Original printf: %d\n", d);
    custom_ret = ft_printf("Custom printf: %d\n", d);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test unsigned integers
    unsigned int u = 456;

    original_ret = printf("Original printf: %u\n", u);
    custom_ret = ft_printf("Custom printf: %u\n", u);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test hexadecimal (lowercase)
    original_ret = printf("Original printf: %x\n", u);
    custom_ret = ft_printf("Custom printf: %x\n", u);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test hexadecimal (uppercase)
    original_ret = printf("Original printf: %X\n", u);
    custom_ret = ft_printf("Custom printf: %X\n", u);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);

    // Test percent sign
    original_ret = printf("Original printf: %%\n");
    custom_ret = ft_printf("Custom printf: %%\n");
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);


    original_ret = printf("Original printf: %c %s %p %d %u %x %X %%\n", c, s, p, d, u, u, u);
    custom_ret = ft_printf("Custom printf: %c %s %p %d %u %x %X %%\n", c, s, p, d, u, u, u);
    printf("Return values - Original: %d, Custom: %d\n\n", original_ret, custom_ret);
    return 0;
}*/