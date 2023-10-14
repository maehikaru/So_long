/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:02:48 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 22:04:30 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_printnstr(char *str, int len)
{
	int	i;

	i = 0;
	if (str != 0)
	{
		while (str[i] && len > i)
		{
			write (1, &str[i], 1);
			i++;
		}
	}
}

void	ft_print_str(va_list *args, t_fcontents *contents)
{
	char	*str;

	str = va_arg(*args, char *);
	if (str == NULL)
	{
		contents->len = 6;
		ft_printnstr("(null)", contents->len);
	}
	else
	{
		contents->len = ft_strlen(str);
		ft_printnstr(str, contents->len);
	}
}
