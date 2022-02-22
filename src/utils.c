/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:52:47 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 13:07:09 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_screen_size(void *mlx_ptr, int *window_width, int *window_height)
{
	mlx_get_screen_size(mlx_ptr, window_width, window_height);
	*window_height -= 100;
	*window_width -= 100;
	if (*window_width > WINDOW_WIDTH || *window_height > WINDOW_HEIGHT)
	{
		*window_width = WINDOW_WIDTH;
		*window_height = WINDOW_HEIGHT;
	}
}

t_point	get_center(void *mlx_ptr)
{
	int		window_width;
	int		window_height;
	t_point	center;

	get_screen_size(mlx_ptr, &window_width, &window_height);
	center.x = window_width / 2;
	center.y = window_height / 2;
	return (center);
}

void	set_point(t_point *point3d, int x, int y, int z)
{
	point3d->x = x;
	point3d->y = y;
	point3d->z = z;
}
