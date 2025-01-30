/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khhihi <khhihi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:01:09 by khhihi            #+#    #+#             */
/*   Updated: 2025/01/29 13:54:56 by khhihi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
void	*ft_malloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif
