/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapConfig.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:21:54 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/02 10:09:44 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAPCONFIG_H
# define FT_MAPCONFIG_H
#include "../.dependencies/libft/libft.h"
#include "../.dependencies/get_next_line/get_next_line.h"
#include "../includes/structures.h"
#include <fcntl.h>
#include <stddef.h>
#include <math.h>

void	ft_setmap(char **premap, t_map *map);

void	ft_readmap(char *file, t_map *map);

void	cleanMap(t_numlist **map);

void isoProj(t_3dcoord coord, t_point *point, void *mlx_ptr);

#endif