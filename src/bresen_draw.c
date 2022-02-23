/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:10 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/23 12:29:46 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bresen_draw.h"

static void	bresen_draw_xcase(t_point start, t_point end, t_fdf *fdf)
{
	float	dx;
	float	dy;
	float	slope;
	float	pitch;
	t_point	current;

	dx = end.x - start.x;
	dy = end.y - start.y;
	slope = dy / dx;
	pitch = start.y - slope * start.x;
	current.x = start.x;
	while (current.x != end.x)
	{	
		current.y = round(slope * current.x + pitch);
		current.color = get_color(current, start, end);
		img_pix_put(fdf, current.x, current.y, current.color);
		current.x += -(dx < 0) + (dx >= 0);
	}
}

static void	bresen_draw_ycase(t_point start, t_point end, t_fdf *fdf)
{
	float	dx;
	float	dy;
	float	slope;
	float	pitch;
	t_point	current;

	dx = end.x - start.x;
	dy = end.y - start.y;
	slope = dx / dy;
	pitch = start.x - slope * start.y;
	current.y = start.y;
	while (current.y != end.y)
	{
		current.x = round(slope * current.y + pitch);
		current.color = get_color(current, start, end);
		img_pix_put(fdf, current.x, current.y, current.color);
		current.y += -(dy < 0) + (dy >= 0);
	}
}

void	bresen_draw(t_point start, t_point end, t_fdf *fdf)
{
	float	dx;
	float	dy;

	start.color = get_default_color(start.z, fdf->map->min, fdf->map->max);
	end.color = get_default_color(end.z, fdf->map->min, fdf->map->max);
	dx = end.x - start.x;
	dy = end.y - start.y;
	if (ft_abs(dy) < ft_abs(dx))
		bresen_draw_xcase(start, end, fdf);
	else if (start.x != end.x && start.y != end.y)
		bresen_draw_ycase(start, end, fdf);
	img_pix_put(fdf, end.x, end.y, end.color);
}
