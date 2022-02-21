/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:58:17 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/21 12:55:26 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_buildmtx(t_mtx *A, int line, int col)
{
	int	i;

	A->line = line;
	A->col = col;
	A->mtx = malloc(line * sizeof(int *));
	i = 0;
	while (i < line)
	{
		(A->mtx)[i] = (int *)malloc(col * sizeof(int));
		i++;
	}
}

void	free_matrix(t_mtx *A)
{
	int	i;

	i = 0;
	while (i < A->line)
	{
		free(A->mtx[i]);
		i++;
	}
	free(A->mtx);
}

void	argc_error_message(int argc)
{
	if (argc == 1)
	{
		ft_putendl_fd("Oh, c'mon dear. I can handle more than that.", 2);
		ft_putendl_fd("Please, insert two arguments so we can procede.", 2);
	}
	else if (argc > 2)
	{
		ft_putendl_fd(
			"Hmm... That's too much. I guess we have try with a little less.",
			2);
		ft_putendl_fd(
			"Please, insert only two arguments so we can procede.", 2);
	}
}

void	type_error_message(void)
{
	ft_putendl_fd("Ops, we don't deal with this type of type.", 2);
	ft_putendl_fd("Please choose an '.fdf' file.", 2);
}

int	check_input_error(int argc, char **argv)
{
	if (argc != 2)
	{
		argc_error_message(argc);
		return (INPUT_ERROR);
	}
	if (!ft_strnstr(argv[1], "fdf", ft_strlen(argv[1])))
	{
		type_error_message();
		return (INPUT_ERROR);
	}
	return (NO_ERROR);
}

static void	get_screen_size(void *mlx_ptr
	, int *window_width, int *window_height)
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

int	init_mlx_window(t_mlxData *mlxData)
{
	int	window_width;
	int	window_height;

	mlxData->mlx_ptr = mlx_init();
	if (!mlxData->mlx_ptr)
		return (MLX_ERROR);
	get_screen_size(mlxData->mlx_ptr, &window_width, &window_height);
	mlxData->win_ptr = mlx_new_window(mlxData->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if (!mlxData->win_ptr)
	{
		mlx_destroy_display(mlxData->mlx_ptr);
		free(mlxData->win_ptr);
		return (MLX_ERROR);
	}
	mlxData->img.mlx_img = mlx_new_image(mlxData->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT);
	mlxData->img.addr = mlx_get_data_addr(mlxData->img.mlx_img,
			&mlxData->img.bpp,
			&mlxData->img.line_len, &mlxData->img.endian);
	mlxData->win_height = window_height;
	mlxData->win_width = window_width;
	return (MLX_INITIALIZED);
}

void	set_point3d(t_3dcoord *point3d, int x, int y, int z)
{
	point3d->x = x;
	point3d->y = y;
	point3d->z = z;
}

void	draw_map(t_mlxData	*mlxData)
{
	t_numlist	*line;
	t_numlist	*col;
	int			idx;
	int			idy;
	t_3dcoord	point3d;
	t_point		origin;
	t_point		final;
	int			delta;

	line = mlxData->map.point;
	col = mlxData->map.point;
	idy = 0;
	delta = mlxData->map.delta;
	while (col)
	{
		idx = 0;
		line = col;
		set_point3d(&point3d, idx, idy, line->value);
		iso_proj(point3d, &origin, mlxData->map.center);
		while (line)
		{
			if (line->down)
			{
				set_point3d(&point3d, idx, idy + delta, line->down->value);
				iso_proj(point3d, &final, mlxData->map.center);
				bresen_draw(origin.x, origin.y, line->value, \
					line->down->value, final.x, final.y, &mlxData->img);
			}
			if (line->right)
			{
				set_point3d(&point3d, idx + delta, idy, line->right->value);
				iso_proj(point3d, &final, mlxData->map.center);
				bresen_draw(origin.x, origin.y, line->value, \
					line->right->value, final.x, final.y, &mlxData->img);
			}
			idx += delta;
			origin.x = final.x;
			origin.y = final.y;
			line = line->right;
		}
		col = col->down;
		idy += delta;
	}
}

static t_point	get_center(void *mlx_ptr)
{
	int		window_width;
	int		window_height;
	t_point	center;

	get_screen_size(mlx_ptr, &window_width, &window_height);
	center.x = window_width / 2;
	center.y = window_height / 2;
	return (center);
}

int	mouse_event(int button, int x, int y, void *param)
{
	printf("%d\n", button);
	printf("%d, %d\n", x, y);
	printf("%p\n", param);
	return (1);
}

int	expose_handle(void)
{
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlxData	fdf;
	char		*file;

	fdf.map.delta = 5;
	if (check_input_error(argc, argv) != NO_ERROR)
		return (INPUT_ERROR);
	if (init_mlx_window(&fdf) != MLX_INITIALIZED)
		return (MLX_ERROR);
	file = argv[1];
	ft_readmap(file, &fdf.map);
	fdf.map.center = get_center(fdf.mlx_ptr);
	draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, \
		fdf.img.mlx_img, 0, 0);
	mlx_loop_hook(fdf.mlx_ptr, &handle_no_event, &fdf);
	mlx_expose_hook(fdf.mlx_ptr, &expose_handle, &fdf);
	mlx_key_hook(fdf.win_ptr, &handle_input, &fdf);
	mlx_hook(fdf.win_ptr, KeyPress, KeyPressMask, \
		&handle_keypress, &fdf);
	mlx_hook(fdf.win_ptr, ClientMessage, None, &close_window, &fdf);
	mlx_mouse_hook(fdf.win_ptr, &mouse_event, &fdf);
	mlx_loop(fdf.mlx_ptr);
	mlx_destroy_image(fdf.mlx_ptr, fdf.img.mlx_img);
	mlx_destroy_display(fdf.mlx_ptr);
	clear_map(&(fdf.map.point));
	free(fdf.mlx_ptr);
}
