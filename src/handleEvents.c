/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEvents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:27:52 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 14:47:53 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/handleEvents.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_input(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		return (0);
	}
	else if (keysym == XK_KP_Add)
		fdf->map->delta += 1;
	else if (keysym == XK_KP_Subtract && fdf->map->delta > 0)
		fdf->map->delta -= 1;
	else if (keysym == XK_Right)
		fdf->map->center.x += 5;
	else if (keysym == XK_Left)
		fdf->map->center.x -= 5;
	else if (keysym == XK_Up)
		fdf->map->center.y -= 5;
	else if (keysym == XK_Down)
		fdf->map->center.y += 5;
	clear_image(fdf);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
			fdf->img->mlx_img, 0, 0);
	return (1);
}

//else if (keysym ==  XK_equal)
//clear_image(mlxData);
//mlx_destroy_window(data->mlx_ptr, data->win_ptr);

int	mouse_event(int button, int x, int y, t_fdf *fdf)
{
	if (button == 5)
	{
		clear_image(fdf);
		fdf->map->delta += 1;
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
			fdf->img->mlx_img, 0, 0);
	}
	else if (button == 4)
	{
		clear_image(fdf);
		if (fdf->map->delta > 0)
			fdf->map->delta -= 1;
		draw_map(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
			fdf->img->mlx_img, 0, 0);
	}
	printf("%d\n", button);
	printf("%d, %d\n", x, y);
	return (1);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	return (0);
}
