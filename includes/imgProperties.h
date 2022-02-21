/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgProperties.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/21 11:06:43 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMGPROPERTIES_H
# define IMGPROPERTIES_H

# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/handleEvents.h"
# include "../includes/fdf.h"
# include "../includes/structures.h"

int	get_default_color(int z, int z_min, int z_max);

int	get_color(t_point current, t_point start, t_point end);

#endif