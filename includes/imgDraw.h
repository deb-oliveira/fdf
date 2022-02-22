/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgDraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 10:53:26 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGDRAW_H
# define IMGDRAW_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/handleEvents.h"
# include "../includes/fdf.h"
# include "../includes/structures.h"

# define BLACK_COLOR 0x000000

void	img_pix_put(t_img *img, int x, int y, int color);

void	bresen_draw(t_point start, t_point end, t_img *img);

void	clear_image(t_fdf *fdf);

#endif