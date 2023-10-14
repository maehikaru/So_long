/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:55:01 by maeharahika       #+#    #+#             */
/*   Updated: 2023/04/10 23:13:44 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_fcontents
{
	int	specifier;
	int	len;
}	t_fcontents;

int		ft_putstr(const char **temp, const char **fmt);
void	ft_putchar_fd(char c, int fd);
int		ft_getdigits(long long num);
void	ft_getlen(t_fcontents *contents, int num, unsigned int unum);
void	ft_gethexlen(t_fcontents *contents, unsigned int unum);
void	ft_getptrlen(t_fcontents *contents, unsigned long long ullnum);
void	ft_printnstr(char *str, int len);
void	ft_putnbr(int n);
void	ft_putunbr(unsigned int un);
void	ft_puthex(unsigned int un, t_fcontents *contents);
void	ft_putptr(unsigned long long ulln);
size_t	ft_strlen(const char *str);
void	ft_init_fcontents(t_fcontents *s);
int		ft_strchr_fn(const char *s, const char c);
int		ft_isdigit(int c);
int		ft_rdy_print(const char **fmt, va_list *args, \
				t_fcontents *contents);
void	ft_print_char(va_list *args, t_fcontents *contents);
void	ft_print_str(va_list *args, t_fcontents *contents);
void	ft_print_pointer(va_list *args, t_fcontents *contents);
void	ft_print_int(va_list *args, t_fcontents *contents);
void	ft_print_unsigned(va_list *args, t_fcontents *contents);
void	ft_print_hex(va_list *args, t_fcontents *contents);
void	ft_print_percent(t_fcontents *contents);
int		ft_formats(const char **fmt, va_list *args);
int		ft_printf(const char *fmt, ...);
#endif
