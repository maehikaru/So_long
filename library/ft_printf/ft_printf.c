/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:29:59 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 21:30:27 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char **temp, const char **fmt)
{
	int	n;

	n = 0;
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *temp, *fmt - *temp);
	n += *fmt - *temp;
	return (n);
}

void	ft_init_fcontents(t_fcontents *s)
{
	s->specifier = -1;
	s->len = 0;
}

int	ft_strchr_fn(const char *s, const char c)
{
	int	i;

	i = 0;
	if (!c)
		return (-1);
	while (*(s + i) != c && *(s + i))
		i++;
	if (*(s + i) == c)
		return (i);
	return (-1);
}

int	ft_formats(const char **fmt, va_list *args)
{
	int			num;
	t_fcontents	contents;

	(*fmt)++;
	ft_init_fcontents(&contents);
	contents.specifier = ft_strchr_fn("cspdiuxX%", **fmt);
	num = ft_rdy_print(fmt, args, &contents);
	return (num);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			n;
	const char	*temp;

	n = 0;
	va_start(args, fmt);
	if (fmt == NULL)
		n = -1;
	while (n >= 0 && *fmt)
	{
		temp = fmt;
		if (*temp != '%')
			n += ft_putstr(&temp, &fmt);
		else
			n += ft_formats(&fmt, &args);
	}
	va_end(args);
	return (n);
}
