/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:46:30 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 16:17:41 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dec_to_hex(unsigned long long n, int lower)
{
	unsigned long long	o;
	char				r;
	char				length;

	o = 0;
	length = 0;
	if (n == 0)
		return (length);
	o = n % 16;
	ft_dec_to_hex((n / 16), lower);
	if (o > 9)
		r = 'A' + (o - 10);
	else
		r = (o + 48);
	if (lower == 1)
		r = ft_tolower(r);
	write(1, &r, 1);
	length++;
	return (length);
}