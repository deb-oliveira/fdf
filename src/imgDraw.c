/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgDraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:37:20 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 11:13:29 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imgDraw.h"
/*make
static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}*/

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (!(x > 0 && y > 0 && x < WINDOW_WIDTH && y < WINDOW_HEIGHT))
		return ;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	clear_image(t_fdf *fdf)
{
	int	i;
	int	j;

	if (fdf->win_ptr == NULL)
		return ;
	i = 0;
	while (i < fdf->win_height)
	{
		j = 0;
		while (j < fdf->win_width)
			img_pix_put(fdf->img, j++, i, 0x000000);
		++i;
	}
}
/*
void	bresen_draw(int x0, int y0, int z0, int z1, int x1, int y1, t_img *img)
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	slope;
	float	pitch;
	t_point	current;
	t_point	start;
	t_point	end;

	start.x = x0;
	end.x = x1;
	start.y = y0;
	end.y = y0;
	start.color = get_default_color(z0, 0, 10);
	end.color = get_default_color(z1, 0, 10);
	if (x0 == x1 && y0 == y1)
	{
		if (x0 > 0 && y0 > 0 && x0 < WINDOW_WIDTH && y0 < WINDOW_HEIGHT)
			img_pix_put(img, x0, y0, 0xFFFFFF);
		return ;
	}
	dx = x1 - x0;
	sx = -(dx < 0) + (dx >= 0);
	dy = y1 - y0;
	sy = -(dy < 0) + (dy >= 0);
	if (ft_abs(dy) < ft_abs(dx))
	{
		slope = dy / dx;
		pitch = y0 - slope * x0;
		while (x0 != x1)
		{
			current.x = x0;
			current.y = round(slope * x0 + pitch);
			current.color = get_color(current, start, end);
			if (current.x > 0 && current.y > 0 && current.x < WINDOW_WIDTH \
				&& current.y < WINDOW_HEIGHT)
				img_pix_put(img, x0, round(slope * x0 + pitch), current.color);
			x0 += sx;
		}
	}
	else
	{
		slope = dx / dy;
		pitch = x0 - slope * y0;
		while (y0 != y1)
		{
			current.x = round(slope * y0 + pitch);
			current.y = y0;
			current.color = get_color(current, start, end);
			if (current.x > 0 && current.y > 0 && current.x < WINDOW_WIDTH \
				&& current.y < WINDOW_HEIGHT)
				img_pix_put(img, round(slope * y0 + pitch), y0, current.color);
			y0 += sy;
		}
	}
	if (x1 > 0 && y1 > 0 && x1 < WINDOW_WIDTH && y1 < WINDOW_HEIGHT)
		img_pix_put(img, x1, y1, 0xFFFFFF);
}*/
