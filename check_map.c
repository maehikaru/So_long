/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:49:17 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:54:30 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pre(int ac, char **av)
{
	char	*p;
	int		fd;

	if (ac != 2)
		exit_error(ERROR_ARGS);
	fd = open_file(av[1]);
	close(fd);
	p = ft_strrchr(av[1], '.');
	if (ft_strncmp(".ber", p, 5))
		exit_error(ERROR_BER);
}

void	check_map(t_map *map)
{
	int	y;

	y = 0;
	map->col = ft_strlen(map->line[y + map->start_row]) - 1;
	while (y + map->start_row <= map->end_row)
	{
		if (!ft_strncmp(map->line[y + map->start_row], "\n", 1))
			error_map(map->line, map->row, ERROR_CLOSEMAP);
		check_wall(map->line[y + map->start_row], map, y);
		check_objs(map->line[y + map->start_row], map, y);
		y++;
	}
}

void	check_wall(char *s, t_map *map, int y)
{
	int	i;

	if (map->col != (int)ft_strlen(s) - 1)
		error_map(map->line, map->row, ERROR_RECT);
	if (y == 0 || y == map->end_row)
	{
		i = 0;
		while (s[i] != '\n')
		{
			if (s[i] != '1')
				error_map(map->line, map->row, ERROR_WALL);
			i++;
		}
	}
	else
	{
		if (s[0] != '1' || s[map->col - 1] != '1')
			error_map(map->line, map->row, ERROR_WALL);
	}
}

void	check_objs(char *s, t_map *map, int y)
{
	static int	i_cnt[2];

	while (*s != '\n')
	{
		if (*s != '1' && *s != '0' && *s != 'C'
			&& *s != 'E' && *s != 'P')
			error_map(map->line, map->row, ERROR_ITEM);
		else if (*s == 'C')
			map->c_cnt += 1;
		else if (*s == 'E')
			i_cnt[0] += 1;
		else if (*s == 'P')
			i_cnt[1] += 1;
		s++;
	}
	if (y + map->start_row == map->end_row)
	{
		if (map->c_cnt == 0)
			error_map(map->line, map->row, ERROR_COLLECT);
		if (i_cnt[0] != 1)
			error_map(map->line, map->row, ERROR_GOAL);
		if (i_cnt[1] != 1)
			error_map(map->line, map->row, ERROR_PLAYER);
	}
}
