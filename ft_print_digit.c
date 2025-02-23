/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaghdas <tbaghdas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:59:48 by tbaghdas          #+#    #+#             */
/*   Updated: 2025/02/23 18:00:33 by tbaghdas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dec2char_hex(int n, int shift)
{
	if (n > 9)
		return ('A' + n - 10 + shift);
	return (n + '0');
}

void	ft_printhex_fd(unsigned int n, int fd, int *count, int shift)
{
	long	nb;
	long	div;

	nb = n;
	div = 16;
	if (nb < 0)
	{
		ft_printchar_fd('-', fd, count);
		nb *= -1;
	}
	while (nb / (div * 16))
	{
		div *= 16;
	}
	while (div > 2 && nb > 9)
	{
		ft_printchar_fd(dec2char_hex((nb / div) % 16, shift), fd, count);
		div /= 16;
	}
	ft_printchar_fd(dec2char_hex(nb % 16, shift), fd, count);
}

void	ft_printptr_fd(void *ptr, int fd, int *count)
{
	unsigned int	high;
	unsigned int	low;
	unsigned int	check;
	int				i;

	high = (unsigned int)(((unsigned long)ptr) >> 32);
	low = (unsigned int)(((unsigned long)ptr) & 0xFFFFFFFF);
	ft_printstr_fd("0x", fd, count);
	if (high)
	{
		i = 0;
		check = !(high^0x00000000);
		if ((check & (0x80000000 >> i)) != 0 && i++ < 32)
			ft_printchar_fd('0', fd, count);
		ft_printhex_fd(high, fd, count, 32);
	}
		i = 0;
		check = !(low^0x00000000);
		if ((check & (0x80000000 >> i)) != 0 && i++ < 32)
			ft_printchar_fd('0', fd, count);
	ft_printhex_fd(low, fd, count, 32);
}

void	ft_printnbr_fd(int n, int fd, int *count)
{
	long	nb;
	long	div;

	nb = n;
	div = 10;
	if (nb < 0)
	{
		ft_printchar_fd('-', fd, count);
		nb *= -1;
	}
	while (nb / (div * 10))
	{
		div *= 10;
	}
	while (div > 2 && nb > 9)
	{
		ft_printchar_fd((nb / div) % 10 + '0', fd, count);
		div /= 10;
	}
	ft_printchar_fd((nb % 10) + '0', fd, count);
}

void	ft_printunbr_fd(unsigned int nb, int fd, int *count)
{
	ft_printnbr_fd(nb / 10, fd, count);
	ft_printnbr_fd(nb % 10, fd, count);
}
