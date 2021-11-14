/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 13:23:24 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/08/26 16:56:23 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# define BUFFER_SIZE	32

char	*ft_strdup2(char *src);

char	*ft_strjoin2(char const *s1, char const *s2);

void	*ft_calloc2(size_t nmemb, size_t size);

size_t	ft_strlen2(char const *str);

void	*ft_memccpy2(void *dest, void *src, int c, size_t n);

int		get_next_line(int fd, char **line);

#endif