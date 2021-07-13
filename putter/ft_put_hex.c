/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 10:44:40 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 09:59:50 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_put_hex(unsigned long long p, int u)
{
	char	*hex;

	hex = malloc(sizeof(char) * 12);
	if (p == 0)
		return ("0");
	if (u == 1)
		return (ft_strupper(ft_dec_to_hex((unsigned long long) p, hex)));
	return (ft_dec_to_hex((unsigned long long) p, hex));
}
