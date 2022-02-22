/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgDraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:37:20 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 16:23:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/imgDraw.h"
#include "../includes/utils.h"

void	img_pix_put(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel;

	if (!(x > 0 && y > 0 && x < fdf->win_width && y < fdf->win_height))
		return ;
	pixel = fdf->img->addr
			+ (y * fdf->img->line_len + x * (fdf->img->bpp / 8));
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
			img_pix_put(fdf, j++, i, 0x000000);
		++i;
	}
}
