/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:18 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:55:16 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **line, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(line[i]);
		i++;
	}
	free(line);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && n--)
	{
		if (*s1 == '\0' || *s2 == '\0' || n == 0)
			return (0);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_strrchr(char *s, int c)
{
	char	cc;
	char	*return_p;

	cc = (char)c;
	return_p = NULL;
	while (*s != '\0')
	{
		if (*s == cc)
			return_p = (char *)s;
		s++;
	}
	if (cc == 0)
		return ((char *)s);
	if (return_p != NULL)
		return (return_p);
	else
		return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*heap;
	size_t	len;

	len = ft_strlen(s) + 1;
	heap = (char *)malloc(sizeof(char) * len);
	if (heap == NULL)
		return (NULL);
	ft_memcpy(heap, s, len);
	return (heap);
}
