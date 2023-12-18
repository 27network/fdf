/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:07:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/18 16:08:45 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <fdf/defaults.h>
#include <fdf/error.h>
#include <fdf/map.h>
#include <fdf/minilibx.h>

int	main(int ac, char *av[])
{
	t_map		map;
	t_fdf_error	error;

	if (ac != 2)
		ft_dprintf(2, PROGRAM_TITLE ": Invalid arguments.\n"
			"Usage: %s <path/to/map.fdf>\n", av[0]);
	if (ac != 2)
		return (-1);
	map.width = 0;
	map.height = 0;
	map.z_matrix = NULL;
	map.color_matrix = NULL;
	error = fdf_map_parse(av[1], &map);
	if (error != FDF_OK)
		ft_dprintf(2, PROGRAM_TITLE": Invalid map: %s.\n", fdf_strerror(error));
	else
		fdf_mlx_init(&map);
	fdf_map_free(&map);
	return (0);
}
