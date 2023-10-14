/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:00 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:54:57 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize(t_solong *solong)
{
	init_window(solong);
	init_objs(solong);
	init_player(solong);
	solong->m_cnt = 0;
	solong->clear = false;
}

void	init_window(t_solong *s)
{
	s->win_w = s->col * BASE;
	s->win_h = s->row * BASE;
	s->mlx = mlx_init();
	if (s->mlx == NULL)
		exit_error(ERROR_MLX);
	s->win = mlx_new_window(s->mlx, s->win_w, s->win_h, "./so_long");
	if (s->win == NULL)
		exit_error(ERROR_MLX);
}

void	init_objs(t_solong *s)
{
	s->player = mlx_xpm_file_to_image(s->mlx, DIR_P, &s->win_w, &s->win_h);
	if (s->player == NULL)
		exit_error(ERROR_MLX);
	s->wall = mlx_xpm_file_to_image(s->mlx, DIR_W, &s->win_w, &s->win_h);
	if (s->wall == NULL)
		exit_error(ERROR_MLX);
	s->space = mlx_xpm_file_to_image(s->mlx, DIR_E, &s->win_w, &s->win_h);
	if (s->space == NULL)
		exit_error(ERROR_MLX);
	s->goal = mlx_xpm_file_to_image(s->mlx, DIR_G, &s->win_w, &s->win_h);
	if (s->goal == NULL)
		exit_error(ERROR_MLX);
	s->collect = mlx_xpm_file_to_image(s->mlx, DIR_C, &s->win_w, &s->win_h);
	if (s->collect == NULL)
		exit_error(ERROR_MLX);
	s->ongoal = mlx_xpm_file_to_image(s->mlx, DIR_O, &s->win_w, &s->win_h);
	if (s->ongoal == NULL)
		exit_error(ERROR_MLX);
}

void	init_player(t_solong *s)
{
	int	x;
	int	y;
	int	flg;

	y = 0;
	flg = 0;
	while (y < s->row)
	{
		x = 0;
		while (x < s->col)
		{
			if (s->line[y][x] == 'P' || s->line[y][x] == 'N')
			{
				s->x = x;
				s->y = y;
				flg = 1;
				break ;
			}
			x++;
		}
		if (flg == 1)
			break ;
		y++;
	}
}

void	init_after_move(t_solong *sl)
{
	draw_objs(sl);
	init_player(sl);
	movelog(sl);
	if (sl->clear == true)
		exit_solong(sl);
}
