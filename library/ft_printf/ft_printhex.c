/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:43:50 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 21:48:49 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int un, t_fcontents *contents)
{
	if (un >= 16)
	{
		ft_puthex(un / 16, contents);
		ft_puthex(un % 16, contents);
	}
	else
	{
		if (un <= 9)
			ft_putchar_fd((un + '0'), 1);
		else
		{
			if (contents->specifier == 6)
				ft_putchar_fd((un - 10 + 'a'), 1);
			else if (contents->specifier == 7)
				ft_putchar_fd((un - 10 + 'A'), 1);
		}
	}
}

void	ft_gethexlen(t_fcontents *contents, unsigned int unum)
{
	int	len;

	len = 0;
	if (unum == 0)
		contents->len = 1;
	else
	{
		while (unum != 0)
		{
			len++;
			unum = unum / 16;
		}
		contents->len = len;
	}
}

void	ft_print_hex(va_list *args, t_fcontents *contents)
{
	unsigned int	unum;

	unum = (unsigned int)va_arg(*args, int);
	ft_gethexlen(contents, unum);
	ft_puthex(unum, contents);
}
