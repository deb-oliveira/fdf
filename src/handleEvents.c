/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEvents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:27:52 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/13 10:38:50 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/handleEvents.h"

static void setPoint3d(t_3dcoord *point3d, int x, int y, int z)
{
	point3d->x = x;
	point3d->y = y;
	point3d->z = z;
}


static void drawMap(t_mlxData	*mlxData)
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
		isoProj(point3d, &origin,  mlxData->map.center);
		while (line)
		{
			if (line->down)
			{
				setPoint3d(&point3d, idx, idy + delta, line->down->value);
				isoProj(point3d, &final, mlxData->map.center);
				bresenDraw(origin.x, origin.y, line->value, line->down->value, final.x, final.y, &mlxData->img);
			}
			if (line->right)
			{
				setPoint3d(&point3d, idx + delta, idy, line->right->value);
				isoProj(point3d,  &final,  mlxData->map.center);
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

int	handle_no_event()
{
	return (0);
}


int	handle_input(int keysym, t_mlxData *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_mlxData *mlxData)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlxData->mlx_ptr, mlxData->win_ptr);
	else if (keysym ==  XK_KP_Add)
	{
		clearImage(mlxData);
		mlxData->map.delta += 1;
		drawMap(mlxData);
		mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->win_ptr, mlxData->img.mlx_img, 0, 0);	
	}
	else if (keysym == XK_KP_Subtract)
	{
		clearImage(mlxData);
		if (mlxData->map.delta > 0)
			mlxData->map.delta -= 1;
		drawMap(mlxData);
		mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->win_ptr, mlxData->img.mlx_img, 0, 0);	
	}
	else if (keysym == XK_Right )
	{
		clearImage(mlxData);
		mlxData->map.center.x += 5;
		drawMap(mlxData);
		mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->win_ptr, mlxData->img.mlx_img, 0, 0);	
	}
	else if (keysym == XK_Left )
	{
		clearImage(mlxData);
		mlxData->map.center.x -= 5;
		drawMap(mlxData);
		mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->win_ptr, mlxData->img.mlx_img, 0, 0);	
	}
	else if (keysym == XK_Up )
	{
		clearImage(mlxData);
		mlxData->map.center.y -= 5;
		drawMap(mlxData);
		mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->win_ptr, mlxData->img.mlx_img, 0, 0);	
	}
	else if (keysym == XK_Down )
	{
		clearImage(mlxData);
		mlxData->map.center.y += 5;
		drawMap(mlxData);
		mlx_put_image_to_window(mlxData->mlx_ptr, mlxData->win_ptr, mlxData->img.mlx_img, 0, 0);	
	}
	//else if (keysym ==  XK_equal)
	 	//clearImage(mlxData);
		//mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	else 
		printf("%d\n", keysym);
	return (0);
}

int	closeWindow(t_mlxData *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}