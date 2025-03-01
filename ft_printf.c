/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaghdas <tbaghdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:59:53 by tbaghdas          #+#    #+#             */
/*   Updated: 2025/03/01 18:01:55 by tbaghdas         ###   ########.fr       */
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
