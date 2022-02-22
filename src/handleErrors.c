/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleErrors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:03:01 by dde-oliv          #+#    #+#             */
/*   Updated: 2022/02/22 13:07:32 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	argc_error_message(int argc)
{
	if (argc == 1)
	{
		ft_putendl_fd("Oh, c'mon dear. I can handle more than that.", 2);
		ft_putendl_fd("Please, insert two arguments so we can procede.", 2);
	}
	else if (argc > 2)
	{
		ft_putendl_fd(
			"Hmm... That's too much. I guess we have try with a little less.",
			2);
		ft_putendl_fd(
			"Please, insert only two arguments so we can procede.", 2);
	}
}

void	type_error_message(void)
{
	ft_putendl_fd("Ops, we don't deal with this type of type.", 2);
	ft_putendl_fd("Please choose an '.fdf' file.", 2);
}

int	check_input_error(int argc, char **argv)
{
	if (argc != 2)
	{
		argc_error_message(argc);
		return (INPUT_ERROR);
	}
	if (!ft_strnstr(argv[1], "fdf", ft_strlen(argv[1])))
	{
		type_error_message();
		return (INPUT_ERROR);
	}
	return (NO_ERROR);
}
