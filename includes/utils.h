/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:57:42 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 15:06:33 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/structures.h"
# include "../includes/fdf.h"

void	set_point(t_point *point3d, int x, int y, int z);

t_point	get_center(void *mlx_ptr);

void	get_screen_size(void *mlx_ptr, int *window_width, int *window_height);

void	iso_proj(t_point *point, t_point center);

int     ft_abs(int x);

#endif