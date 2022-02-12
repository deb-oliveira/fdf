/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleEvents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 21:27:52 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/01/13 23:51:58 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/handleEvents.h"

int	handle_no_event()
{
	return (0);
}

int	handle_input(int keysym, t_mlxData *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_mlxData *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	closeWindow(t_mlxData *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}