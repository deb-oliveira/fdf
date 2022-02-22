/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgDraw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:37:20 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 17:04:46 by dde-oliv         ###   ########.fr       */
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

void	draw_menu(t_fdf	*fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->win_ptr;
	mlx_string_put(mlx, win, 50, y += 50, 0xffffff, "ISOMETRIC PROJECTION");
	mlx_string_put(mlx, win, 50, y += 35, 0xffffff,
		"Press 'ESC' or click the 'X' at the upper \
right side to close the windows.");
	mlx_string_put(mlx, win, 50, y += 20, 0xffffff,
		"Press the arrow keys to move the map.");
	mlx_string_put(mlx, win, 50, y += 20, 0xffffff,
		"Use the mouse to Zoom In or Zoom Out.");
}
