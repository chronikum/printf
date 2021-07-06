/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 13:35:42 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	int i;
	int l;
	char *beginning;
	
	i = 0;
	l = 0;
	beginning = "";
	va_start(args, format);
	while (format[i])
	{
		if (format[i - 1] == '%' && ft_is_available_type((char *) &format[i], beginning))
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
				l += ft_putstr(ft_put_hex(va_arg(args, unsigned long long), 0));
			if (format[i] == 'X')
				l += ft_putstr(ft_put_hex(va_arg(args, unsigned long long), 1));
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
	char *testpointer = "TEST";
	ft_printf("Teasdasdasdsdst! %d %% %d %s Das ist ziemlich cool! %% test mich %u %i %p %x\n", 555, 4444, "TESTSTRING", 429496729, 12, testpointer, 888888);
	//    printf("Teasdasdasdsdst! %d %-d %s Das ist ziemlich cool! %% test mich %u %i %p %x", 123123, 4444, "TESTSTRING", 429496729, 12, testpointer, 888888);
	printf("  %10d   \n", 1212);
	printf("  %s   \n", "TEST");

	printf("  %d   ", 123);

	return 0;
}