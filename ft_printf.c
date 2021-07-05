/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 09:50:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int argc;
	va_list args;
	int i;
	int arg_found_counter;

	argc = 0;
	i = 0;
	arg_found_counter = 0;
	
	argc = ft_argument_count((char *)format);
	if (argc == 0)
	{
		ft_putstr_fd((char *) format, 1);
		return 0;
	}
	
	va_start(args, format);
	while (format[i])
	{
		if (format[i - 1] == '%' && ft_is_available_type(format[i]))
		{
			if (format[i] == 'd')
			{
				int iprint = va_arg(args, int);
				ft_putnbr_fd(iprint, 1);
			}
			if (format[i] == 'c')
			{
				int cprint = va_arg(args, int);
				ft_putchar_fd((char) cprint, 1);
			}
			if (format[i] == 's')
			{
				char *cpprint = va_arg(args, char*);
				ft_putstr_fd(cpprint, 1);
			}
			if (format[i] == 'u')
			{
				unsigned int usiprint = va_arg(args, unsigned int);
				ft_putunbr_fd(usiprint, 1);
			}
		} 
		else if ((format[i] == '%' && format[i - 1] == '%') || format[i] != '%')
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return 0;
}


int main()
{
	ft_printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u\n", 123123, 4444, "TESTSTRING", -1);
	   printf("Teasdasdasdsdst! %d %d %s Das ist ziemlich cool! %% test mich %u", 123123, 4444, "TESTSTRING", -1);

	return 0;
}