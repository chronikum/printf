/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:59:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/06 09:55:32 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putaddr_fd(void *p)
{
	char *addr = malloc(sizeof(char) * 12);
	char *prefix = "0x";
	if (!p)
		return "0x0";
	return ft_strjoin(prefix, ft_dec_to_hex((unsigned long long) p, addr));
}
