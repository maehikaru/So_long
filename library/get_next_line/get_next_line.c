/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:46:03 by maeharahika       #+#    #+#             */
/*   Updated: 2023/05/16 01:37:47 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_check_save(char *save, int fd)
{
	char	*tmp;
	ssize_t	readnum;

	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	readnum = 1;
	while (!ft_strchr(save, '\n') && readnum != 0)
	{
		readnum = read(fd, tmp, BUFFER_SIZE);
		if (readnum == -1)
		{
			free(save);
			free(tmp);
			return (NULL);
		}
		tmp[readnum] = '\0';
		save = tmp_join_save(save, tmp);
	}
	free(tmp);
	return (save);
}

static size_t	is_lastline(char *save, size_t i)
{
	size_t	res;

	res = 0;
	if (save[i] == '\n')
		res = i + 2;
	else
		res = i + 1;
	return (res);
}

static char	*put_line(char *save)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (is_lastline(save, i)));
	if (!tmp)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		tmp[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		tmp[i] = '\n';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*update_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen_gnl(save) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_check_save(save, fd);
	if (!save)
		return (NULL);
	line = put_line(save);
	save = update_save(save);
	return (line);
}
