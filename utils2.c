/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:23 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:55:20 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	unsigned const char	*p_src;

	if (dest == src)
		return (dest);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned const char *)src;
	while (n--)
		*p_dest++ = *p_src++;
	return (dest);
}
