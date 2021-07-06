/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 10:48:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int l;
	
	i = 0;
	l = 0;
	
	va_start(args, format);
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
				ft_putstr(ft_putaddr_fd(va_arg(args, void *)));
			if (format[i] == 'x')
				ft_putstr(ft_put_hex(va_arg(args, unsigned long long)));
		} 
		else if ((format[i] == '%' && format[i - 1] == '%') || format[i] != '%')
			l += ft_putchar(format[i]);
		i++;

	}
	va_end(args);
	return 0;
}


int main()
{
	
	ft_printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u %i %p %x\n", 123123, 4444, "TESTSTRING", 429496729, 12, NULL, 123123);
	   printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u %i %p %x", 123123, 4444, "TESTSTRING", 429496729, 12, NULL, 123123);

	return 0;
}