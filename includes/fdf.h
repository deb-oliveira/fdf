/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:58:28 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 13:05:29 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define MLX_ERROR -1
# define NO_ERROR 1
# define INPUT_ERROR -1
# define MLX_INITIALIZED 1
# define WINDOW_WIDTH 1300
# define WINDOW_HEIGHT 680
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "../.dependencies/libft/libft.h"
# include "../.dependencies/get_next_line/get_next_line.h"
# include "../includes/handleEvents.h"
# include "../includes/handleErrors.h"
# include "../includes/imgProperties.h"
# include "../includes/structures.h"
# include "../includes/mapConfig.h"
# include "../includes/imgDraw.h"
# include "../includes/bresen_draw.h"
# include "../includes/draw_map.h"
# include "../includes/utils.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
#  define BLACK_COLOR 0x000000
# endif

void	draw_map(t_fdf	*fdf);

#endif