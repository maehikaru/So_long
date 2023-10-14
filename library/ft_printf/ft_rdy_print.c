/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdy_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:27:42 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 21:31:34 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_rdy_print(const char **fmt, va_list *args, \
		t_fcontents *contents)
{
	if (contents->specifier == -1)
		return (-1);
	(*fmt)++;
	if (contents->specifier == 0)
		ft_print_char(args, contents);
	else if (contents->specifier == 1)
		ft_print_str(args, contents);
	else if (contents->specifier == 2)
		ft_print_pointer(args, contents);
	else if (contents->specifier == 3 || contents->specifier == 4)
		ft_print_int(args, contents);
	else if (contents->specifier == 5)
		ft_print_unsigned(args, contents);
	else if (contents->specifier == 6 || contents->specifier == 7)
		ft_print_hex(args, contents);
	else
		ft_print_percent(contents);
	return (contents->len);
}
