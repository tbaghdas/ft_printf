
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);

void	ft_printunbr_fd(unsigned int nb, int fd, int *count);
void	ft_printnbr_fd(int n, int fd, int *count);
void	ft_printptr_fd(void *ptr, int fd, int *count);
void	ft_printhex_fd(unsigned int n, int fd, int *count, int shift);
void	ft_printstr_fd(char *s, int fd, int *count);
int		ft_printchar_fd(char c, int fd, int *count);
void	ft_putchar_fd(char c, int fd);

#endif
