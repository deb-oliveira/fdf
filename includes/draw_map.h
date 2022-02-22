/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:55:45 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 12:57:04 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_H
# define DRAW_MAP_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/structures.h"
# include "../includes/imgDraw.h"
# include "../includes/fdf.h"

void	draw_map(t_fdf	*fdf);

void	draw_edges(t_numlist *line, t_point start, int delta, t_fdf *fdf);

#endif