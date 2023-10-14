/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:09:29 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 15:05:50 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_solong	solong;
	t_map		map;

	check_pre(ac, av);
	get_map_info(&map, av[1]);
	check_map(&map);
	set_map_to_solong(&map, &solong);
	initialize(&solong);
	check_playable(&solong);
	draw_objs(&solong);
	mlx_hook(solong.win, X_EVENT_KEY_RELEASE, 0, &key_press, &solong);
	mlx_hook(solong.win, X_EVENT_KEY_EXIT, 0, &exit_solong, &solong);
	mlx_loop(solong.mlx);
	return (0);
}
