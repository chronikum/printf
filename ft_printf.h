#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_argument_count(char *format);
int	ft_is_available_type(char *str, char *beginning);
int	ft_printf(const char *format, ...);


int		ft_putchar(char c);
int		ft_putint(int n);
int 	ft_putstr(char *c);
int		ft_putuint(unsigned int n);
void	ft_putunlonglong(unsigned long long n, int fd);
char	*ft_put_hex(unsigned long long p, int u);
#endif
