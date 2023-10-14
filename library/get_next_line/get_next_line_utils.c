/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:45:52 by maeharahika       #+#    #+#             */
/*   Updated: 2023/10/14 15:09:30 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*sub_tjs(char *s, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	*null_check(char *s1, char *s2)
{
	char	*res;

	res = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		res = sub_tjs(s2, ft_strlen_gnl(s2));
	else
		res = sub_tjs(s1, ft_strlen_gnl(s1));
	return (res);
}

char	*tmp_join_save(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (null_check(s1, s2));
	tmp = (char *)malloc(sizeof(char) * \
		(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!tmp)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		tmp[i++] = s2[j++];
	tmp[ft_strlen_gnl(s1) + ft_strlen_gnl(s2)] = '\0';
	free(s1);
	return (tmp);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
