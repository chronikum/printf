/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 16:46:22 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

/*
	Writes the detected pattern with the flags and the type in the char
	pointer "pattern".
	Will return the length if the first index of format is the beginning of the
	pattern and it is also valid.
	This pattern can be used afterwards in the ft_str function.
	If it is invalid, the return value will be equal to 0

	This works by counting how long a pattern is - we will start
	counting beginning from %. After that we check for the allowed
	symbols: -0.* until we found one of the "cdpdiuxXs" flags.
*/
static int ft_get_pattern(char *format, char **pattern)
{
	int length;
	
	length = 0;
	if (format[0] == '%')
	{
		while (ft_inset(format[length], "-0.*") 
			|| (ft_inset(format[length], "cdpdiuxXs%")))
		{
			length++;
			if (ft_inset(format[length], "cdpdiuxXs%"))
				break;
		}
		printf("%d", length);
		*pattern = format;
	}

	if (length == 0)
		return (0);
	return length;
}

static void	ft_match_type(char *format, va_list args, int l)
{
	int i;
	char *pattern;

	i = 0;
	while (format[i])
	{
		int length = ft_get_pattern(&format[i], &pattern);
		if (format[i - (1 + length)] == '%' && ft_is_available_type(format[i]))
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
			if (format[i] == '%')
				l += ft_putstr("%");
		} 
		else if (format[i] != '%')
			l += ft_putchar(format[i]);
		i++;
	}
}

/*
	You know what printf does do you?
*/
int ft_printf(const char *format, ...)
{
	va_list args;
	int l;
	char *beginning;
	
	l = 0;
	beginning = "";
	va_start(args, format);
	ft_match_type((char *) format, args, l);
	va_end(args);
	return 0;
}


int main()
{
	char *testpointer = "TEST";
	ft_printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u %i %p %x\n", 123123, 4444, "TESTSTRING", 429496729, 12, testpointer, 888888);
	   printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u %i %p %x", 123123, 4444, "TESTSTRING", 429496729, 12, testpointer, 888888);
	printf("  %10d   \n", 1212);
	printf("  %s   \n", "TEST");

	printf("  %d   ", 123);

	return 0;
}