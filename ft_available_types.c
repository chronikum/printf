/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_available_types.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:26:20 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 14:13:03 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	ft_matches_type(char c)
// {
// 	if (c == 'c' || c == 'd' || c == 'p' || c == 'd' || c == 'i'
// 		|| c == 'u' || c == 'x' || c == 'X' || c == 's')
// 		return (1);
// 	return (0);
// }

// static int	ft_matches_flag(char c)
// {
// 	if (c == '-' || c == '0' || c == '.' || c == 'X')
// 		return (1);
// 	return (0);
// }

// static int	ft_inset(char c, char const *set)
// {
// 	int	count;

// 	count = 0;
// 	while (set[count])
// 	{
// 		if (c == set[count])
// 			return (1);
// 		count++;
// 	}
// 	return (0);
// }

int	ft_is_available_type(char c)
{	
	if (c == 'c' || c == 'd' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 's' || c == '%')
		return (1);
	return (0);
}
