/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaghdas <tbaghdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:59:40 by tbaghdas          #+#    #+#             */
/*   Updated: 2025/02/23 18:22:02 by tbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

int	ft_printchar_fd(char c, int fd, int *count)
{
	ft_putchar_fd(c, fd);
	return (++*count);
}

void	ft_printstr_fd(char *s, int fd, int *count)
{
	if (s == NULL)
	{
		ft_printstr_fd("(null)", fd, count);
		return ;
	}
	while (*s != '\0')
		ft_printchar_fd(*s++, fd, count);
}
