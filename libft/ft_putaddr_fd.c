/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 09:59:01 by jfritz            #+#    #+#             */
/*   Updated: 2021/07/05 15:26:36 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_putaddr_fd(void *p)
{
	char *str = "";
	printf("TEST: %s", ft_dec_to_hex((unsigned long long) p, str));
	return ft_dec_to_hex((unsigned long long) p, str);
}
