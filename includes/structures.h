/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:21:54 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/23 10:40:15 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_numlist
{
	int					value;
	struct s_numlist	*right;
	struct s_numlist	*down;
}				t_numlist;

typedef struct s_map
{
	int			width;
	int			height;
	int			delta;
	int			max;
	int			min;
	t_point		center;
	t_numlist	*point;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_width;
	t_img	*img;
	t_map	*map;
}	t_fdf;

#endif