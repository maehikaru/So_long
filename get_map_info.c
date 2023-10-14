/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:49:54 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 15:07:42 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_info(t_map *map, char *map_file)
{
	int	i;

	map->filepath = map_file;
	map_rowcount(map);
	if (!(map->row))
		exit_error(ERROR_EMPTY);
	map->fd = open_file(map->filepath);
	map->line = malloc(sizeof(char *) * map->row);
	if (map->line == NULL)
		exit_error(ERROR_MALLOC);
	map->c_cnt = 0;
	i = 0;
	while (i < map->row)
	{
		map->line[i] = get_next_line(map->fd);
		if (map->line[i] == NULL)
			error_malloc_array(map->line, i);
		i++;
	}
	find_map_row(map);
}

void	map_rowcount(t_map *map)
{
	int		buf_size;
	char	*buf;

	map->fd = open_file(map->filepath);
	buf_size = (MAX_FILE_ROW + 1) * (MAX_MAP_COL + 1);
	buf = malloc(sizeof(char) * buf_size);
	if (buf == NULL)
		exit_error(ERROR_MALLOC);
	if (read(map->fd, buf, buf_size) == -1)
		exit_error(ERROR_READ);
	count_mapsize(buf, &map->row);
	free(buf);
	close(map->fd);
}

void	find_map_row(t_map *map)
{
	int	i;

	i = 0;
	while (!ft_strncmp(map->line[i], "\n", 1))
	{
		i++;
		if (i >= map->row)
			error_map(map->line, map->row, ERROR_EMPTY);
	}
	map->start_row = i;
	i = map->row - 1;
	while (!ft_strncmp(map->line[i], "\n", 1) && i >= 0)
		i--;
	map->end_row = i;
}

void	count_mapsize(char *buf, int *set_row)
{
	int		row_cnt;
	int		col_cnt;
	char	*tmp;

	row_cnt = 0;
	col_cnt = 0;
	tmp = buf;
	while (*tmp)
	{
		if (*tmp == '\n')
		{
			row_cnt++;
			col_cnt = 0;
		}
		else
			col_cnt++;
		if (col_cnt > MAX_MAP_COL || row_cnt > MAX_FILE_ROW)
		{
			free(buf);
			exit_error(ERROR_BIG_MAP);
		}
		tmp++;
	}
	*set_row = row_cnt;
}

int	open_file(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
	{
		error_ftprintf(ERROR_FILE);
		exit(0);
	}
	return (fd);
}
