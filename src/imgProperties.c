/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgProperties.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:05:36 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/21 11:34:24 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imgProperties.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

int	get_default_color(int z, int z_min, int z_max)
{
	double	percentage;

	percentage = percent(z_min, z_max, z);
	if (percentage < 0.2)
		return (0xfeebe2);
	else if (percentage < 0.4)
		return (0xfbb4b9);
	else if (percentage < 0.6)
		return (0xf768a1);
	else if (percentage < 0.8)
		return (0xc51b8a);
	else
		return (0x7a0177);
}

int	get_color(t_point current, t_point start, t_point end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (start.color == end.color)
		return (start.color);
	if (ft_abs(end.x - start.x) > ft_abs(end.y - start.y))
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = (int)((1 - percentage)
			* ((start.color >> 16) & 0xFF) + percentage
			* ((end.color >> 16) & 0xFF));
	green = (int)((1 - percentage)
			* ((start.color >> 8) & 0xFF) + percentage
			* ((end.color >> 8) & 0xFF));
	blue = (int)((1 - percentage)
			* (start.color & 0xFF) + percentage * (end.color & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}
