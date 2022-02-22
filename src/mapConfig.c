/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapConfig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:26:53 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 13:08:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mapConfig.h"
#include "../includes/fdf.h"

void	iso_proj(t_point *point, t_point center)
{
	int	x;
	int	y;
	int	z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = center.x + round(sqrt(2.0) / 2.0
			* (x - y));
	point->y = center.y * 0.2 - round(sqrt(2.0 / 3.0)
			* z - sqrt(1.0 / 6.0)
			* (x + y));
}	

static void	ft_doublefree(char **tofree)
{
	int	idx;

	if (!tofree)
		return ;
	idx = 0;
	while (tofree[idx])
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
	if (idx > map->width)
		map->width = idx;
}

void	ft_readmap(char *file, t_map *map)
{
	int			gnl;
	char		*line;
	char		**premap;
	int			fd;
	int			i;

	fd = open(file, O_RDONLY);
	gnl = 1;
	map->point = NULL;
	map->height = 0;
	map->width = 0;
	i = 1;
	while (gnl > 0)
	{
		gnl = get_next_line(fd, &line);
		premap = ft_split(line, ' ');
		if (premap && premap[0] && ft_strcmp(premap[0], "") != 0)
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

void	clear_map(t_numlist **map)
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
