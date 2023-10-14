/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmaehara <hmaehara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:49:48 by hmaehara          #+#    #+#             */
/*   Updated: 2023/10/14 14:54:49 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_map(char **line, int row, const char *msg)
{
	free_array(line, row);
	exit_error(msg);
}

void	error_file(int fd, char *s, const char *msg)
{
	free(s);
	close(fd);
	exit_error(msg);
}

void	error_malloc_array(char **s, int i)
{
	free_array(s, i);
	exit_error(ERROR_MALLOC);
}

void	exit_error(const char *message)
{
	error_ftprintf(message);
	exit(0);
}
