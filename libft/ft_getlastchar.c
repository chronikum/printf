/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlastchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 14:21:40 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 14:25:22 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns the last char in a char pointer.
	Cannot handle strings with zero length.
*/

char ft_getlastchar(char *str)
{
	return str[ft_strlen(str) - 1];
}