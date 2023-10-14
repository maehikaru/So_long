/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_to_solong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:14 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:55:12 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map_to_solong(t_map *map, t_solong *sl)
{
	int	y;
	int	size;

	y = 0;
	size = map->end_row - map->start_row + 1;
	sl->line = malloc(sizeof(char *) * size);
	if (sl->line == NULL)
		exit_error(ERROR_MALLOC);
	while (y + map->start_row <= map->end_row)
	{
		sl->line[y] = ft_strdup(map->line[y + map->start_row]);
		if (sl->line[y] == NULL)
		{
			free_array(map->line, map->row);
			error_malloc_array(sl->line, y);
		}
		y++;
	}
	sl->row = size;
	sl->col = map->col;
	sl->c_cnt = map->c_cnt;
	free_array(map->line, map->row);
}
