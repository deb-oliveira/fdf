/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:58:28 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/11/14 11:44:29 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MLX_ERROR 1
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 600
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include "../.dependencies/libft/libft.h"
#include "../.dependencies/get_next_line/get_next_line.h"
#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif



typedef struct s_point
{
	int	x;
	int	y;
	int	color;
}				t_point;

typedef struct s_3dcoord
{
	int	x;
	int	y;
}				t_3dcoord;

typedef struct s_numlist
{
	int					value;
	struct s_numlist	*right;
	struct s_numlist	*down;
}				t_numlist;

typedef struct s_mtx
{
	int		line;
	int		col;
	int		**mtx;
}				t_mtx;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp; /* bits per pixel */
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_param
{
	void *mlx_ptr;
	void *img_ptr;
	t_img img;
} t_param;
void bresenDraw(int x0, int y0, int z0, int z1, int x1, int y1, t_img *img);//void **mlx_ptr, void **win_ptr)
#endif