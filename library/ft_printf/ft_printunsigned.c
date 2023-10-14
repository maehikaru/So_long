/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:27:33 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 21:47:16 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int un)
{
	if (un < 10)
		ft_putchar_fd ((un + '0'), 1);
	else
	{
		ft_putunbr (un / 10);
		ft_putchar_fd (((un % 10) + '0'), 1);
	}
}

void	ft_print_unsigned(va_list *args, t_fcontents *contents)
{
	unsigned int	unum;

	unum = (unsigned int)va_arg(*args, int);
	ft_getlen(contents, 0, unum);
	ft_putunbr(unum);
}
