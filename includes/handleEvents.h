/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEvents.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:28:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/01/13 22:47:09 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLEEVENTS_H
# define FT_HANDLEEVENTS_H

#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "../includes/structures.h"


int	handle_no_event();

int	handle_input(int keysym, t_mlxData *data);

int	handle_keypress(int keysym, t_mlxData *data);

int	closeWindow(t_mlxData *data);

#endif