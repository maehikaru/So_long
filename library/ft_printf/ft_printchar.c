/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:34:45 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 22:00:16 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(va_list *args, t_fcontents *contents)
{
	int	c;

	c = (char) va_arg (*args, int);
	write (1, &c, 1);
	contents->len = 1;
}
