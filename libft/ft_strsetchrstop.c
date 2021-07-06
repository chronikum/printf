/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsetchrstop.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:32:53 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 13:34:30 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_inset(char c, char const *set, char *tc)
{
	int	count;

	count = 0;
	while (set[count] && (c != *tc))
	{
		if (c == set[count])
		{
			tc[0] = c;
			return (1);
		}
		count++;
	}
	return (0);
}

/*
	Returns the pointer of first encounter of a set of chars. Searches only
	until the stopchar was found or there is a null char in the string
*/
char	*ft_strsetchrstop(char *str, char *set, char stop)
{
	int		i;
	char *tc;

	tc = malloc(sizeof(char));

	i = 0;
	if (!set)
		return (NULL);
	while (str[i] && (str[i] != stop))
	{
		if (ft_inset(str[i], set, tc))
			return tc;
		i++;
	}
	
	return (NULL);
}
