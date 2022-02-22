/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:58:17 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 15:08:50 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	init_mlx_window(t_fdf *fdf)
{
	int	window_width;
	int	window_height;

	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (MLX_ERROR);
	get_screen_size(fdf->mlx_ptr, &window_width, &window_height);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!fdf->win_ptr)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->win_ptr);
		return (MLX_ERROR);
	}
	fdf->img->mlx_img = mlx_new_image(fdf->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	fdf->img->addr = mlx_get_data_addr(fdf->img->mlx_img,
			&fdf->img->bpp,
			&fdf->img->line_len, &fdf->img->endian);
	fdf->win_height = window_height;
	fdf->win_width = window_width;
	return (MLX_INITIALIZED);
}

int	init_fdf(int argc, char **argv, t_fdf **fdf)
{
	char	*file;

	(*fdf) = malloc(sizeof(t_fdf));
	(*fdf)->map = malloc(sizeof(t_map));
	(*fdf)->img = malloc(sizeof(t_img));
	(*fdf)->map->delta = 20;
	if (check_input_error(argc, argv) != NO_ERROR)
		return (INPUT_ERROR);
	if (init_mlx_window(*fdf) != MLX_INITIALIZED)
		return (MLX_ERROR);
	file = argv[1];
	ft_readmap(file, (*fdf)->map);
	(*fdf)->map->center = get_center((*fdf)->mlx_ptr);
	draw_map(*fdf);
	return (1);
}

void	close_fdf(t_fdf *fdf)
{
	clear_map(&(fdf->map->point));
	free(fdf->mlx_ptr);
	free(fdf->img);
	free(fdf->map);
	free(fdf);
}

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	if (init_fdf(argc, argv, &fdf) != FDF_INITIALIZED)
		return (FDF_ERROR);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, \
		fdf->img->mlx_img, 0, 0);
	mlx_loop_hook(fdf->mlx_ptr, &handle_no_event, fdf);
	mlx_key_hook(fdf->win_ptr, &handle_input, fdf);
	mlx_hook(fdf->win_ptr, KeyPress, KeyPressMask, \
		&handle_keypress, fdf);
	mlx_hook(fdf->win_ptr, ClientMessage, None, &close_window, fdf);
	mlx_mouse_hook(fdf->win_ptr, &mouse_event, fdf);
	mlx_loop(fdf->mlx_ptr);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img->mlx_img);
	mlx_destroy_display(fdf->mlx_ptr);
	close_fdf(fdf);
}
