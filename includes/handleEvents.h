/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEvents.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/23 13:15:01 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLEEVENTS_H
# define HANDLEEVENTS_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/structures.h"
# include "../includes/imgDraw.h"
# include "../includes/fdf.h"

int	handle_no_event(void);

int	expose_hook(t_fdf *fdf);

int	handle_keypress(int keysym, t_fdf *fdf);

int	close_window(t_fdf *fdf);

int	mouse_event(int button, int x, int y, t_fdf *fdf);

#endif