/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgDraw.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 17:01:26 by dde-oliv         ###   ########.fr       */
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
# include "../includes/bresen_draw.h"

# define BLACK_COLOR 0x000000

void	img_pix_put(t_fdf *fdf, int x, int y, int color);

void	clear_image(t_fdf *fdf);

int		draw_menu(t_fdf	*fdf);
#endif