/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:46:20 by maeharahika       #+#    #+#             */
/*   Updated: 2023/05/16 01:46:37 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*get_next_line(int fd);
char	*tmp_join_save(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen_gnl(const char *str);

#endif
