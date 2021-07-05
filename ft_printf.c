/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 15:21:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 09:21:07 by jfritz           ###   ########.fr       */
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
		if (format[i - 1] == '%' && format[i] != '%')
		{
			if (format[i] == 'd')
			{
				int iprint = va_arg(args, int);
				ft_putnbr_fd(iprint, 1);
				arg_found_counter++;
			}
			if (format[i] == 'c')
			{
				int cprint = va_arg(args, int);
				ft_putchar_fd((char) cprint, 1);
				arg_found_counter++;
			}
			if (format[i] == 's')
			{
				char *cpprint = va_arg(args, char*);
				ft_putstr_fd(cpprint, 1);
				arg_found_counter++;
			}
		} 
		else if (format[i] != '%')
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
	ft_printf("Teasdasdasdsdst! %d %s Das ist ziemlich cool!\n", 123123, "Test! Again");
	printf("Teasdasdasdsdst! %d %s Das ist ziemlich cool!", 123123, "Test! Again");

	return 0;
}