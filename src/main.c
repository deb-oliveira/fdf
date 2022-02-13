/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:58:17 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/13 10:23:28 by dde-oliv         ###   ########.fr       */
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

void	freeMatrix(t_mtx *A)
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

void argcErrorMessage(int argc)
{
	if (argc == 1)
	{
		ft_putendl_fd("Oh, c'mon dear. I can handle more than that.", 2);
		ft_putendl_fd("Please, insert two arguments so we can procede.", 2);
	}
	else if (argc > 2)
	{
		ft_putendl_fd("Oh, dear! That's too much. I guess we have try with a little less.", 2);
		ft_putendl_fd("Please, insert only two arguments so we can procede.", 2);
	}
}

void typeErrorMessage()
{
	ft_putendl_fd("Ops, we don't deal with this type of type.", 2);
	ft_putendl_fd("Please choose an '.fdf' file.", 2);
}

int checkInputError(int argc, char **argv)
{
	if (argc != 2)
	{
		argcErrorMessage(argc);
		return(INPUT_ERROR);
	}
	if (!ft_strnstr(argv[1], "fdf", ft_strlen(argv[1]))){
		typeErrorMessage();
		return (INPUT_ERROR);
	}
	return(NO_ERROR);
}

static void getScreenSize(void *mlx_ptr, int *windowWidth, int *windowHeight)
{
	mlx_get_screen_size(mlx_ptr, windowWidth, windowHeight);
	*windowHeight -= 100;
	*windowWidth -= 100;
	if (*windowWidth > WINDOW_WIDTH || *windowHeight > WINDOW_HEIGHT)
	{
		*windowWidth = WINDOW_WIDTH;
		*windowHeight = WINDOW_HEIGHT;
	}
}

int initMlxWindow(t_mlxData *mlxData)
{
	int windowWidth;
	int windowHeight;
	
	mlxData->mlx_ptr = mlx_init();
	if (!mlxData->mlx_ptr)
		return (MLX_ERROR);
	getScreenSize(mlxData->mlx_ptr, &windowWidth, &windowHeight);
	mlxData->win_ptr = mlx_new_window(mlxData->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	if(!mlxData->win_ptr)
	{
		mlx_destroy_display(mlxData->mlx_ptr);
		free(mlxData->win_ptr);
		return (MLX_ERROR);
	}
	mlxData->img.mlx_img = mlx_new_image(mlxData->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlxData->img.addr = mlx_get_data_addr(mlxData->img.mlx_img, &mlxData->img.bpp,
			&mlxData->img.line_len, &mlxData->img.endian);
	mlxData->winHeight = windowHeight;
	mlxData->winWidth = windowWidth;	
	return (MLX_INITIALIZED);
	
}

void setPoint3d(t_3dcoord *point3d, int x, int y, int z)
{
	point3d->x = x;
	point3d->y = y;
	point3d->z = z;
}



void drawMap(t_mlxData	*mlxData)
{
	t_numlist	*line;
	t_numlist	*col;
	int			idx;
	int			idy;
	t_3dcoord	point3d;
	//t_mtx		cord3d;
	t_point		origin;
	t_point		final;
	int			delta;

	line = mlxData->map.point;
	col = mlxData->map.point;
	
	idy = 0;
	delta = mlxData->map.delta;
	//printf("%d, %d", getCenterOfScren(mlxData->mlx_ptr).x, getCenterOfScren(mlxData->mlx_ptr).y);
	while (col)
	{
		idx = 0;
		line = col;
		setPoint3d(&point3d, idx, idy, line->value);
		isoProj(point3d, &origin, mlxData->mlx_ptr);
		while (line)
		{
			if (line->down)
			{
				setPoint3d(&point3d, idx, idy + delta, line->down->value);
				isoProj(point3d, &final, mlxData->mlx_ptr);
				bresenDraw(origin.x, origin.y, line->value, line->down->value, final.x, final.y, &mlxData->img);
			}
			if (line->right)
			{
				setPoint3d(&point3d, idx + delta, idy, line->right->value);
				isoProj(point3d,  &final, mlxData->mlx_ptr);
				bresenDraw(origin.x, origin.y, line->value, line->right->value, final.x, final.y, &mlxData->img);
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

int	main(int argc, char **argv)
{
	t_mlxData 	mlxData;
	char		*file;
	//t_numlist	*map;
	
	mlxData.map.delta = 5;
	if(checkInputError(argc, argv) != NO_ERROR)
		return (INPUT_ERROR);
	if(initMlxWindow(&mlxData) != MLX_INITIALIZED)
		return (MLX_ERROR);
	
	file = argv[1];
	ft_readmap(file, &mlxData.map);
	drawMap(&mlxData);
	
	mlx_put_image_to_window(mlxData.mlx_ptr, mlxData.win_ptr, mlxData.img.mlx_img, 0, 0);		
	mlx_loop_hook(mlxData.mlx_ptr, &handle_no_event, &mlxData);
	//mlx_key_hook(mlxData.win_ptr, &handle_input, &mlxData);
	mlx_hook(mlxData.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &mlxData);
	mlx_hook(mlxData.win_ptr, ClientMessage, None, &closeWindow, &mlxData);
	mlx_loop(mlxData.mlx_ptr);
	
	mlx_destroy_image(mlxData.mlx_ptr, mlxData.img.mlx_img);
	mlx_destroy_display(mlxData.mlx_ptr);
	cleanMap(&(mlxData.map.point));
	free(mlxData.mlx_ptr);

}