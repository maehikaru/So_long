/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:49:36 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 15:08:15 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	go_next(int dir, int *m, t_track *bt);

int	dfs_goal(int vert, int hori, t_track *bt)
{
	int	dir;
	int	m[2];

	if (bt->line[vert][hori] == 'E')
		return (1);
	bt->line[vert][hori] = 'x';
	dir = 0;
	while (dir < 4)
	{
		m[0] = vert;
		m[1] = hori;
		if (go_next(dir, m, bt) != -1)
		{
			if (dfs_goal(m[0], m[1], bt))
				return (1);
		}
		dir++;
	}
	return (0);
}

int	dfs_collect(int vert, int hori, t_track *bt)
{
	int	dir;
	int	m[2];

	if (bt->line[vert][hori] == 'C')
	{
		if (!(--bt->c_cnt))
			return (1);
		bt->line[vert][hori] = '0';
	}
	bt->line[vert][hori] = 'x';
	dir = 0;
	while (dir < 4)
	{
		m[0] = vert;
		m[1] = hori;
		if (go_next(dir, m, bt) != -1)
		{
			if (dfs_collect(m[0], m[1], bt))
				return (1);
		}
		dir++;
	}
	return (0);
}

static	int	go_next(int dir, int *m, t_track *bt)
{
	if (dir == 0)
	{
		if (!(bt->line[m[0] - 1][m[1]] == '1')
			&& !(bt->line[m[0] - 1][m[1]] == 'x'))
			return (m[0]--);
	}
	else if (dir == 1)
	{
		if (!(bt->line[m[0]][m[1] + 1] == '1')
			&& !(bt->line[m[0]][m[1] + 1] == 'x'))
			return (m[1]++);
	}
	else if (dir == 2)
	{
		if (!(bt->line[m[0] + 1][m[1]] == '1')
			&& !(bt->line[m[0] + 1][m[1]] == 'x'))
			return (m[0]++);
	}
	else if (dir == 3)
	{
		if (!(bt->line[m[0]][m[1] - 1] == '1')
			&& !(bt->line[m[0]][m[1] - 1] == 'x'))
			return (m[1]--);
	}
	return (-1);
}
