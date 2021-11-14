/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:58:17 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/11/14 11:21:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_coord2d(int x, int y, int z, t_point *point)
{
	point->x = 400 + round(0.7071 * (x - y));
	point->y = 300 - round(0.8165 * z - 0.4082 * (x + y));
}

void isoProj(t_mtx coord, t_point *point)
{
	int x;
	int y;
	int z;

	x = coord.mtx[0][0];
	y = coord.mtx[1][0];
	z = coord.mtx[2][0];
	point->x = 250 + round(sqrt(2.0)/2.0 * (x - y));
	point->y = 200 - round(sqrt(2.0/3.0) * z - sqrt(1.0/6.0) * (x + y));
}	

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

double	ft_scalarprod(t_mtx u, t_mtx v)
{
	int			dim;
	double		uv;

	if (u.line != 1 || v.line != 1 || (u.col != v.col))
		return (INFINITY);
	dim = 0;
	uv = 0;
	while (dim < u.col)
	{
		uv += u.mtx[0][dim] * v.mtx[0][dim];
		dim++;
	}
	return (uv);
}

t_mtx	ft_matrixprod(t_mtx A, t_mtx B)
{
	int		i;
	int		j;
	int		k;
	t_mtx	AB;

	if (A.col != B.line)
	{
		AB.mtx = NULL;
		return (AB);
	}
	ft_buildmtx(&AB, A.line, B.col);
	i = 0;
	while (i < AB.line)
	{
		j = 0;
		while (j < AB.col)
		{
			k = 0;
			AB.mtx[i][j] = 0;
			while (k < A.col)
			{
				AB.mtx[i][j] += A.mtx[i][k] * B.mtx[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (AB);
}

void	iso_proj(t_mtx X, t_point *point)
{
	//t_mtx	A;
	//t_mtx	B;
	//t_mtx	AB;
	//t_mtx	ABX;
	/*double	grad;

	grad = asin(tan(30 * M_PI  / 180));
	ft_buildmtx(&A, 3, 3);
	ft_buildmtx(&B, 3, 3);
	A.mtx[0][0] = 1;
	A.mtx[0][1] = 0;
	A.mtx[0][2] = 0;
	A.mtx[1][0] = 0;
	A.mtx[1][1] = cos(grad * M_PI  / 180);
	A.mtx[1][2] = sin(grad * M_PI  / 180);
	A.mtx[2][0] = 0;
	A.mtx[2][1] = -sin(grad * M_PI  / 180);
	A.mtx[2][2] = cos(grad * M_PI  / 180);
	grad = 45.0;
	B.mtx[0][0] = cos(grad * M_PI  / 180);
	B.mtx[0][1] = 0;
	B.mtx[0][2] = -sin(grad * M_PI  / 180);
	B.mtx[1][0] = 0;
	B.mtx[1][1] = 1;
	B.mtx[1][2] = 0;
	B.mtx[2][0] = sin(grad * M_PI  / 180);
	B.mtx[2][1] = 0;
	B.mtx[2][2] = cos(grad * M_PI  / 180);
	if(X.col != 1 || X.line !=3)
		return ;
	AB = ft_matrixprod(A, B);
	//ABX = ft_matrixprod(AB, X);
	B.mtx[0][0] = 0.7071;
	B.mtx[0][1] = 0;
	B.mtx[0][2] = 0.7071;
	B.mtx[1][0] = 0.4082;
	B.mtx[1][1] = 0.8166;
	B.mtx[1][2] = -0.4082;
	B.mtx[2][0] = 0;
	B.mtx[2][1] = 0;
	B.mtx[2][2] = 0;
	//ABX = ft_matrixprod(B, X);
	point->x = (X.mtx[0][0] - X.mtx[2][0])/sqrt(2);
	point->y = (X.mtx[0][0] + 2*X.mtx[1][0]+ X.mtx[0][0])/sqrt(6);*/
	point->x = 200 + 2 * round((X.mtx[0][0] - X.mtx[1][0]) * cos(0.523599));
	point->y = 100 + 2 * (-X.mtx[2][0] + round((X.mtx[0][0] + X.mtx[1][0]) * sin(0.523599)));
}

t_mtx	ft_rotation(char axle, double grad)
{
	t_mtx	R;

	ft_buildmtx(&R, 3, 3);
	if (axle == 'x')
	{
		R.mtx[0][0] = 1;
		R.mtx[0][1] = 0;
		R.mtx[0][2] = 0;
		R.mtx[1][0] = 0; 
		R.mtx[1][1] = cos(grad * M_PI  / 180);
		R.mtx[1][2] = -sin(grad * M_PI  / 180);
		R.mtx[2][0] = 0;
		R.mtx[2][1] = sin(grad * M_PI  / 180);
		R.mtx[2][2] = cos(grad * M_PI  / 180);
	}	
	else if (axle == 'y')
	{
		R.mtx[0][0] = cos(grad * M_PI  / 180);
		R.mtx[0][1] = 0;
		R.mtx[0][2] = sin(grad * M_PI  / 180);
		R.mtx[1][0] = 0;
		R.mtx[1][1] = 1;
		R.mtx[1][2] = 0;
		R.mtx[2][0] = -sin(grad * M_PI  / 180);
		R.mtx[2][1] = 0;
		R.mtx[2][2] = cos(grad * M_PI  / 180);
	}
	else if (axle == 'z')
	{
		R.mtx[0][0] = cos(grad * M_PI  / 180);
		R.mtx[0][1] = -sin(grad * M_PI  / 180);
		R.mtx[0][2] = 0;
		R.mtx[1][0] = sin(grad * M_PI  / 180);
		R.mtx[1][1] = cos(grad * M_PI  / 180);
		R.mtx[1][2] = 0;
		R.mtx[2][0] = 0;
		R.mtx[2][1] = 0;
		R.mtx[2][2] = 1;
	}
	return(R);
}

void	cleanMap(t_numlist **map)
{
	t_numlist	*ptr_right;
	t_numlist	*ptr_down;
	t_numlist	*ptr_actual;

	ptr_down = NULL;
	ptr_right = NULL;
	ptr_actual = *map;
	while (ptr_actual)
	{
		ptr_right = ptr_actual->right;
		while (ptr_actual->down)
		{
			ptr_down = ptr_actual->down;
			free(ptr_actual);
			ptr_actual = ptr_down;
		}
		free(ptr_actual);
		ptr_actual = ptr_right;
	}
}

void	ft_setmap(char **premap, t_numlist **map)
{
	int			idx;
	t_numlist	*ptr_actual;
	t_numlist	*ptr_previous;

	if (!premap)
		return ;
	if (!*map)
	{
		*map = ft_calloc(1, sizeof(t_numlist));
		ptr_previous = NULL;
		ptr_actual = *map;
	}
	else
	{
		ptr_previous = *map;
		while (ptr_previous->down)
			ptr_previous = ptr_previous->down;
		ptr_previous->down = ft_calloc(1, sizeof(t_numlist));
		ptr_actual = ptr_previous->down;
	}
	idx = 0;
	while (premap[idx])
	{
		ptr_actual->value = ft_atoi(premap[idx]);
		if (premap[idx + 1])
		{
			ptr_actual->right = ft_calloc(1, sizeof(t_numlist));
			if (ptr_previous && ptr_previous->right)
			{
				ptr_previous = ptr_previous->right;
				ptr_previous->down = ptr_actual->right;
			}
		}
		ptr_actual = ptr_actual->right;
		idx++;
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

void	ft_doublefree(char **tofree)
{
	int	idx;

	if (!tofree)
		return ;
	idx = 0;
	while(tofree[idx])
	{
		free(tofree[idx]);
		idx++;
	}
	free(tofree);
}

void	ft_readmap(char *file, t_numlist **map)
{
	int			gnl;
	char		*line;
	char		**premap;
	int			fd;
	
	fd = open(file, O_RDONLY);
	gnl = 1;
	*map = NULL;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		premap = ft_split(line, ' ');
		ft_setmap(premap, map);
		free(line);
		ft_doublefree(premap);
	}
	close(fd);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	handle_no_event()
{
	return (0);
}

int	handle_input(int keysym, t_param *data)
{
	if (keysym == 0xff1b)
		mlx_destroy_window(data->mlx_ptr, data->img_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_point		origin;
	t_point		final;
	int			idx;
	int			idy;
	char		*file;
	t_numlist	*map;
	t_numlist	*line;
	t_numlist	*col;
	t_mtx		cord3d;
	//t_mtx		R;

	if (argc == 1)
	{
		ft_putendl_fd("Oh, c'mon dear. I can handle more than that.", 2);
		return (-1);
	}
	else if (argc > 2)
	{
		ft_putendl_fd("Oh, dear! That's too much for me. I guess we have try with a little less", 2);
		return (-1);
	}
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (MLX_ERROR);
	file = argv[1];
	ft_readmap(file, &map);
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello world!");
	if(!win_ptr)
	{
		mlx_destroy_display(mlx_ptr);
		free(win_ptr);
		return (MLX_ERROR);
	}
	line = map;
	col = map;
	idy = 0;

	t_param mlx_p;
	mlx_p.img_ptr = win_ptr;
	mlx_p.mlx_ptr = mlx_ptr;

	mlx_p.img.mlx_img = mlx_new_image(mlx_p.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);

	mlx_p.img.addr = mlx_get_data_addr(mlx_p.img.mlx_img, &mlx_p.img.bpp,
			&mlx_p.img.line_len, &mlx_p.img.endian);
	
	while (col)
	{
		idx = 0;
		line = col;
		ft_buildmtx(&cord3d, 3, 1);
		(cord3d.mtx)[0][0] = idx;
		(cord3d.mtx)[1][0] = idy;
		(cord3d.mtx)[2][0] = line->value;
		//R  = ft_rotation('z', 0);
		//cord3d = ft_matrixprod(R, cord3d);
		isoProj(cord3d, &origin);
		while (line)
		{
			if (line->down)
			{
				cord3d.mtx[0][0] = idx;
				cord3d.mtx[1][0] = idy + 20;
				cord3d.mtx[2][0] = line->down->value;
				//R  = ft_rotation('z', 0);
				//cord3d = ft_matrixprod(R, cord3d);
				isoProj(cord3d, &final);
				bresenDraw(origin.x, origin.y, line->value, line->down->value, final.x, final.y, &mlx_p.img);
			}
			if (line->right)
			{
				cord3d.mtx[0][0] = idx + 20;
				cord3d.mtx[1][0] = idy;
				cord3d.mtx[2][0] = line->right->value;
				//R  = ft_rotation('z', 0);
				//cord3d = ft_matrixprod(R, cord3d);
				isoProj(cord3d,  &final);
				bresenDraw(origin.x, origin.y, line->value, line->right->value, final.x, final.y, &mlx_p.img);
			
			}

			idx +=20;
			origin.x = final.x;
			origin.y = final.y;
			line = line->right;
		}
		col = col->down;
		idy += 20;
		freeMatrix(&cord3d);
	}


	mlx_put_image_to_window(mlx_p.mlx_ptr, mlx_p.img_ptr, mlx_p.img.mlx_img, 0, 0);
		
	mlx_loop_hook(mlx_p.mlx_ptr, &handle_no_event, &mlx_p);
	mlx_key_hook(mlx_p.img_ptr, &handle_input, &mlx_p);

	mlx_loop(mlx_ptr);
	cleanMap(&map);
	mlx_destroy_image(mlx_p.mlx_ptr, mlx_p.img.mlx_img);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);

}


int ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int get_color(t_point current, t_point start, t_point end)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (start.color == end.color)
        return (start.color);
    if (ft_abs(end.x - start.x) > ft_abs(end.y - start.y))
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);
    red = (int)((1 - percentage) 
		* ((start.color >> 16) & 0xFF) + percentage * ((end.color >> 16) & 0xFF));
	green = (int)((1 - percentage) 
		* ((start.color >> 8) & 0xFF) + percentage * ((end.color >> 8) & 0xFF));
    blue = (int)((1 - percentage) 
		* (start.color & 0xFF) + percentage * (end.color & 0xFF));
    return ((red << 16) | (green << 8) | blue);
}

int	get_default_color(int z, int z_min, int z_max)
{
	double	percentage;

	percentage = percent(z_min, z_max, z);
	/*
	#feebe2
#fbb4b9
#f768a1
#c51b8a
#7a0177
	if (percentage < 0.2)
		return (0xffffb2);
	else if (percentage < 0.4)
		return (0xfecc5c);
	else if (percentage < 0.6)
		return (0xfd8d3c);
	else if (percentage < 0.8)
		return (0xf03b20);
	else
		return (0xbd0026);*/
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


void bresenDraw(int x0, int y0, int z0, int z1, int x1, int y1,t_img *img) // void **mlx_ptr, void **win_ptr, 
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float 	slope;
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
		img_pix_put(img, x0, y0, 0xFFFFFF);
		//mlx_pixel_put(*mlx_ptr, *win_ptr, x0, y0, 0xFFFFFF);
		return ;
	}
	dx = x1 - x0;
	sx = -(dx < 0) + (dx >= 0);
	dy = y1 - y0;
	sy = -(dy < 0) + (dy >= 0);
	if (ft_abs(dy) < ft_abs(dx))
	{
		slope = dy/dx;
		pitch = y0 - slope * x0;
		while (x0 != x1)
		{
			current.x = x0;
			current.y = round(slope * x0 + pitch);
			current.color = get_color(current, start, end);
			img_pix_put(img, x0, round(slope * x0 + pitch), current.color);
			x0 += sx;
		}
	}
	else
	{
		slope = dx/dy;
		pitch = x0 - slope * y0;
		while (y0 != y1)
		{
			current.x = round(slope * y0 + pitch);
			current.y = y0;
			current.color = get_color(current, start, end);
			img_pix_put(img,round(slope * y0 + pitch), y0, current.color);
			//mlx_pixel_put(*mlx_ptr, *win_ptr, round(slope * y0 + pitch), y0, current.color);
			y0 += sy;
		}
	}
	img_pix_put(img, x1, y1, 0xFFFFFF);
	//mlx_pixel_put(*mlx_ptr, *win_ptr, x1, y1, 0xFFFFFF);
}