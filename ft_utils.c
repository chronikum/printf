/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 07:51:18 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 08:35:45 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_argument_count(char *format)
{
	char percent;
	int count;

	count = 0;
	percent = '%';
	while (ft_strchr(format, (int) percent) != NULL)
	{
		format = ft_strchr(format, (int) percent);
		format++;
		count++;
	}
	return count;
}