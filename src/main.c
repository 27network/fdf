/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 01:07:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 15:56:44 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <fdf/defaults.h>
#include <fdf/error.h>
#include <fdf/map.h>
#include <fdf/render/minilibx.h>
#include <fdf/render/vertex.h>

static void	fdf_init(t_map *map, t_vertex_buffer *vb)
{
	map->width = 0;
	map->height = 0;
	map->z_matrix = NULL;
	map->color_matrix = NULL;
	vb->vertices_count = 0;
	vb->vertices = NULL;
	vb->edges_count = 0;
	vb->edges = NULL;
}

int	main(int ac, char *av[])
{
	t_map			map;
	t_vertex_buffer	vertex_buffer;
	t_fdf_error		error;

	if (ac != 2)
		ft_dprintf(2, PROGRAM_TITLE ": Invalid arguments.\n"
			"Usage: %s <path/to/map.fdf>\n", av[0]);
	if (ac != 2)
		return (-1);
	fdf_init(&map, &vertex_buffer);
	error = fdf_map_parse(av[1], &map);
	if (error != FDF_OK)
		ft_dprintf(2, PROGRAM_TITLE": Invalid map: %s.\n", fdf_strerror(error));
	else
	{
		error = fdf_vb_build(&map, &vertex_buffer);
		if (error != FDF_OK)
			ft_dprintf(2, PROGRAM_TITLE": Error while creating "
				"vertex buffer: %s.\n", fdf_strerror(error));
		else
			fdf_mlx_init(&vertex_buffer);
	}
	fdf_vb_free(&vertex_buffer);
	fdf_map_free(&map);
	return (0);
}
