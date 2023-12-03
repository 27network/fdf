/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:07:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/03 01:07:52 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <fdf/defaults.h>
#include <fdf/error.h>
#include <fdf/map.h>
#include <fdf/mlx.h>

int	main(int ac, char *av[])
{
	t_map	map;

	if (ac != 2)
	{
		ft_dprintf(2, PROGRAM_TITLE ": Invalid arguments.\n"
			"Usage: %s <path/to/map.fdf>\n", av[0]);
		return (1);
	}
	if (!fdf_map_parse(av[1], &map))
		ft_dprintf(2, PROGRAM_TITLE ": Invalid map: %m.\n");
	fdf_mlx_init(&map);
	fdf_map_free(&map);
	return (0);
}
