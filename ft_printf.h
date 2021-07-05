#ifndef PRINTF_H
# define PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int ft_argument_count(char *format);
int ft_is_available_type(char c);
int ft_printf(const char *format, ...);

#endif
