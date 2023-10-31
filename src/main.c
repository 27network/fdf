/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:07:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/31 04:32:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_handle_args(char *av[2])
{
	t_map	*map;

	if (av[1]
	return (0);
}

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_putstr_fd(PROGRAM_TITLE ": Invalid arguments.", STANDARD_ERROR);
		ft_putstr_fd(" Usage: ", STANDARD_ERROR);
		ft_putstr_fd(av[0], STANDARD_ERROR);
		ft_putendl_fd(" <path/to/map.ber>", STANDARD_ERROR);
		return (1);
	}
	return (ft_handle_args(av));
}
