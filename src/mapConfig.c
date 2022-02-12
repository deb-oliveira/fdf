/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapConfig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:26:53 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/12 13:45:49 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapConfig.h"
#include "../includes/fdf.h"

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

t_point getCenterOfScreen(void *mlx_ptr)
{
	int windowWidth;
	int windowHeight;
	t_point centerCoord;
	
	getScreenSize(mlx_ptr, &windowWidth, &windowHeight);
	centerCoord.x = windowWidth/2;
	centerCoord.y = windowHeight/2;
	return(centerCoord);
}

void isoProj(t_3dcoord point3d, t_point *point2d, void *mlx_ptr)
{
	t_point centerOfScreen;
	
	centerOfScreen = getCenterOfScreen(mlx_ptr);
	point2d->x = centerOfScreen.x + round(sqrt(2.0)/2.0 * (point3d.x - point3d.y));
	point2d->y = centerOfScreen.y * 0.2 - round(sqrt(2.0/3.0) * point3d.z - sqrt(1.0/6.0) * (point3d.x + point3d.y));
}	


static void	ft_doublefree(char **tofree)
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

void	ft_setmap(char **premap, t_map *map)
{
	int			idx;
	t_numlist	*ptr_actual;
	t_numlist	*ptr_previous;

	if (!premap)
		return ;
	if (!map->point)
	{
		map->point = ft_calloc(1, sizeof(t_numlist));
		ptr_previous = NULL;
		ptr_actual = map->point;
	}
	else
	{
		ptr_previous = map->point;
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
	if ( idx > map->width)
		map->width = idx;
}

void	ft_readmap(char *file, t_map *map)
{
	int			gnl;
	char		*line;
	char		**premap;
	int			fd;

	fd = open(file, O_RDONLY);
	gnl = 1;
	map->point = NULL;
	map->height = 0;
	map->width = 0;
	int i = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		premap = ft_split(line, ' ');
       	if(premap && premap[0] && ft_strcmp(premap[0],"")!=0)
		{
			map->height += 1;
			ft_setmap(premap, map);
			i++;
		}
		free(line);
		ft_doublefree(premap);
	}
	close(fd);
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
		ptr_down = ptr_actual->down;
		while (ptr_actual->right)
		{
			ptr_right = ptr_actual->right;
			free(ptr_actual);
			ptr_actual = ptr_right;
		}
		free(ptr_actual);
		ptr_actual = ptr_down;
	}
}

