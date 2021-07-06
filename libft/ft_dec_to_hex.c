/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:46:30 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 15:55:34 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char *ft_append_character(char *str, char c)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	
	while (str[i])
	{
		ret[i] = str[i];
		printf("%c", str[i]);
		i++;
	}
	ret[i] = c;
	i++;
	ret[i] = '\0';
	return ret;
}

char	*ft_dec_to_hex(unsigned long long n, char *str)
{
	unsigned long long	o = 0;
	
	if(n == 0)
	{
		printf("DONE!");
		return str;
	}
	o=n % 16;
	ft_dec_to_hex(n/16, str);
	if(o > 9)
	{
		char c = 'A' + (o - 10);
		str = ft_append_character(str, c);
	}
	else
	{
		str = ft_append_character(str, (o + 48));
	}
	printf("TEST %s  TEST", str);
	return str;
}