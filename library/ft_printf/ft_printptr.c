/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:04:48 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 21:43:12 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putptr(unsigned long long ulln)
{
	if (ulln >= 16)
	{
		ft_putptr(ulln / 16);
		ft_putptr(ulln % 16);
	}
	else
	{
		if (ulln <= 9)
			ft_putchar_fd((ulln + '0'), 1);
		else
			ft_putchar_fd((ulln - 10 + 'a'), 1);
	}
}

void	ft_getptrlen(t_fcontents *contents, unsigned long long ullnum)
{
	int	len;

	len = 0;
	if (ullnum == 0)
		contents->len = 1;
	else
	{
		while (ullnum != 0)
		{
			len++;
			ullnum = ullnum / 16;
		}
		contents->len = len;
	}
	contents->len += 2;
}

void	ft_print_pointer(va_list *args, t_fcontents *contents)
{
	unsigned long long	ullnum;

	ullnum = va_arg(*args, unsigned long long);
	ft_getptrlen(contents, ullnum);
	write (1, "0x", 2);
	ft_putptr(ullnum);
}
