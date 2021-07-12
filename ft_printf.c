/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/12 16:01:46 by jfritz           ###   ########.fr       */
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


int main()
{
	char *testpointer = NULL;
	int int1 = 2147483647;
	int int2 = 4444;
	int int3 = -123;
	int int4 = -444;
	
	int ml = ft_printf("Teasdasdasdsdst! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Das ist ziemlich cool! %% %% %% test mich %u %i %p %x %s %d\n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4);
	int pl =    printf("Teasdasdasdsdst! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Das ist ziemlich cool! %% %% %% test mich %u %i %p %x %s %d\n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4);

	int ml2 =    printf("AAA %% AAA %d\n", -0);
	int pl2 =    printf("AAA %% AAA %d\n", -0);
	printf("================\n");
	printf("PRINTFLENGTH: %d\n", ml);
	printf("PRINTFLENGTH: %d\n", pl);
	printf("================\n");
	printf("PRINTFLENGTH: %d\n", ml2);
	printf("PRINTFLENGTH: %d\n", pl2);
	return 0;
}