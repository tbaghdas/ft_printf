

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
	if (!s)
	{
		*count = -1;
		return ;
	}
	while (*s)
		ft_printchar_fd(*s++, fd, count);
}
