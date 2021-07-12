/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/12 16:54:36 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h" 

static int	ft_match_type(char *format, va_list args, int l)
{
	int i;
	int p;

	i = 0;
	p = 0;
	while (format[i])
	{
		if (format[i - 1] == '%' && ft_is_available_type(format[i]))
		{
			if (format[i] == 'd' || format[i] == 'i')
				l += ft_putint(va_arg(args, int));
			if (format[i] == 'c')
				l += ft_putchar((char) va_arg(args, int));
			if (format[i] == 's')
				l += ft_putstr(va_arg(args, char *));
			if (format[i] == 'u')
				l += ft_putuint(va_arg(args, unsigned int));
			if (format[i] == 'p')
				l += ft_putstr(ft_putaddr_fd(va_arg(args, void *)));
			if (format[i] == 'x')
				l += ft_putstr(ft_put_hex(va_arg(args, unsigned int), 0));
			if (format[i] == 'X')
				l += ft_putstr(ft_put_hex(va_arg(args, unsigned int), 1));
			if (format[i] == '%')
			{
				p++;
				if (p % 2 == 0)
					l += ft_putchar('%');
			}
		} 
		else if (format[i] != '%')
			l += ft_putchar(format[i]);
		if (format[i + 1] != '%')
			p = 1;
		i++;
	}
	return (l + 1);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int l;
	char *beginning;
	
	l = 0;
	beginning = "";
	va_start(args, format);
	l = ft_match_type((char *) format, args, l);
	va_end(args);
	return l;
}