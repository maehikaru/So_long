/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:50:09 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:55:09 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movelog(t_solong *sl)
{
	ft_printf("movecount: %d\n", ++sl->m_cnt);
}

void	error_ftprintf(char const *message)
{
	ft_printf("ERROR\n --> %s\n", message);
}
