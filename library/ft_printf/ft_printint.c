/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:16:42 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 22:10:34 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getdigits(long long num)
{
	long long		i;
	int				size;

	i = num;
	size = 1;
	if (i < 0)
		i = -i;
	while (10 <= i)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

void	ft_getlen(t_fcontents *contents, int num, unsigned int unum)
{
	if (contents->specifier == 3 || contents->specifier == 4)
		contents->len = ft_getdigits(num);
	else if (contents->specifier == 5)
		contents->len = ft_getdigits(unum);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "2147483648", 10);
	else
	{
		if (n < 0)
		{
			n = -n;
			ft_putnbr (n);
		}
		else if (n < 10)
		{
			ft_putchar_fd((n + '0'), 1);
		}
		else
		{
			ft_putnbr (n / 10);
			ft_putchar_fd(((n % 10) + '0'), 1);
		}
	}
}

void	ft_print_int(va_list *args, t_fcontents *contents)
{
	int	num;

	num = va_arg(*args, int);
	ft_getlen(contents, num, 0);
	if (num < 0)
	{
		write (1, "-", 1);
		contents->len += 1;
	}
	ft_putnbr(num);
}
