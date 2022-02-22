/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleErrors.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:37 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 13:09:25 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLEERRORS_H
# define HANDLEERRORS_H
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../includes/structures.h"
# include "../includes/imgDraw.h"
# include "../includes/fdf.h"

void	argc_error_message(int argc);

void	type_error_message(void);

int		check_input_error(int argc, char **argv);

#endif