/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 13:32:28 by jfritz           ###   ########.fr       */
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
				ft_putaddr_fd(va_arg(args, void *), 1);
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
	char *pointed = "Pointed";
	ft_printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u %i %p\n", 123123, 4444, "TESTSTRING", 429496729, 12, (unsigned long long) &pointed);
	   printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u %i %llu", 123123, 4444, "TESTSTRING", 429496729, 12, (unsigned long long) &pointed);

	return 0;
}