/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresen_draw.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:09:49 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 09:03:47 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRESEN_DRAW_H
# define BRESEN_DRAW_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/handleEvents.h"
# include "../includes/fdf.h"
# include "../includes/structures.h"

# define BLACK_COLOR 0x000000

void	bresen_draw(t_point start, t_point end, t_img *img);

#endif