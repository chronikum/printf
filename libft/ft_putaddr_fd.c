/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:59:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/13 16:20:18 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../ft_printf.h"

int	ft_putaddr_fd(void *p)
{
	char	*addr;
	char	*prefix;
	int		l;

	l = 0;
	if (!p)
		return (ft_putstr("0x0"));
	prefix = "0x";
	addr = malloc(sizeof(char) * 12);
	if (!addr)
		return (ft_putstr("0x0"));
	l += ft_putstr("0x");
	l += ft_dec_to_hex((unsigned long long) p, 1);
	return (l);
}
