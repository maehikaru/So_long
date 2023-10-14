/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:49:40 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:54:46 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_objs(t_solong *solong, void *objs, int w, int h);

void	draw_objs(t_solong *solong)
{
	int	i;
	int	j;

	i = 0;
	while (i < solong->row)
	{
		j = 0;
		while (j < solong->col)
		{
			if (solong->line[i][j] == '1')
				put_objs(solong, solong->wall, j * BASE, i * BASE);
			else if (solong->line[i][j] == '0')
				put_objs(solong, solong->space, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'C')
				put_objs(solong, solong->collect, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'P')
				put_objs(solong, solong->player, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'E')
				put_objs(solong, solong->goal, j * BASE, i * BASE);
			else if (solong->line[i][j] == 'N')
				put_objs(solong, solong->ongoal, j * BASE, i * BASE);
			j++;
		}
		i++;
	}
}

static void	put_objs(t_solong *solong, void *objs, int w, int h)
{
	mlx_put_image_to_window(solong->mlx, solong->win, objs, w, h);
}
