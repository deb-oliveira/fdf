/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEvents.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/21 12:54:39 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLEEVENTS_H
# define HANDLEEVENTS_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/structures.h"
# include "../includes/imgDraw.h"

int	handle_no_event(void);

int	handle_input(int keysym, t_mlxData *data);

int	handle_keypress(int keysym, t_mlxData *data);

int	close_window(t_mlxData *data);

#endif