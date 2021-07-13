/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:46:30 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 09:56:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_dec_to_hex(unsigned long long n, char *str)
{
	unsigned long long	o;
	char				r[2];

	o = 0;
	if (n == 0)
		return (str);
	o = n % 16;
	ft_dec_to_hex((n / 16), str);
	if (o > 9)
	{
		r[0] = 'A' + (o - 10);
	}
	else
	{
		r[0] = (o + 48);
	}
	r[1] = '\0';
	r[0] = ft_tolower(r[0]);
	str = ft_strcat(str, &r[0]);
	return (str);
}
