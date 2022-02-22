/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:51:01 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 13:08:35 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_edges(t_numlist *line, t_point start, int delta, t_fdf *fdf)
{
	t_point		end;
	int			x;
	int			y;

	x = start.x;
	y = start.y;
	iso_proj(&start, fdf->map->center);
	while (line)
	{
		if (line->down)
		{
			set_point(&end, x, y + delta, line->down->value);
			iso_proj(&end, fdf->map->center);
			bresen_draw(start, end, fdf->img);
		}
		if (line->right)
		{
			set_point(&end, x += delta, y, line->right->value);
			iso_proj(&end, fdf->map->center);
			bresen_draw(start, end, fdf->img);
		}
		set_point(&start, end.x, end.y, end.z);
		line = line->right;
	}
}

void	draw_map(t_fdf	*fdf)
{
	t_numlist	*line;
	t_point		start;
	int			delta;
	int			y;

	line = fdf->map->point;
	delta = fdf->map->delta;
	y = -delta;
	while (line)
	{
		set_point(&start, 0, y += delta, line->value);
		draw_edges(line, start, delta, fdf);
		line = line->down;
	}
}
