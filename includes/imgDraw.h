/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgDraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/12 14:48:01 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMGDRAW_H
# define FT_IMGDRAW_H

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "../includes/handleEvents.h"
#include "../includes/fdf.h"
#include "../includes/structures.h"

#define BLACK_COLOR 0x000000

void	img_pix_put(t_img *img, int x, int y, int color);

void bresenDraw(int x0, int y0, int z0, int z1, int x1, int y1,t_img *img);

void clearImage (t_mlxData *mlxData);

#endif