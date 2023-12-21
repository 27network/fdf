/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:59:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/22 00:12:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <ft/mem.h>

static void	fdf_vb_set_vertex(
	t_map *map,
	t_vertex_buffer *vb,
	size_t idx
) {
	vb->vertices[idx].x = idx % map->width;
}

static void	fdf_vb_fill_vertices(t_map *map, t_vertex_buffer *vb)
{
	size_t		x;
	size_t		y;
	size_t		idx;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			idx = y * map->width + x;
			vb->vertices[idx].x = x;
			vb->vertices[idx].y = y;
			vb->vertices[idx].z = map->z_matrix[idx];
			vb->vertices[idx].color
				= fdf_colorpack_int(map->color_matrix[idx]);
		}
		y++;
	}
}

t_fdf_error	fdf_vb_build(t_map *map, t_vertex_buffer *vb)
{
	t_fdf_error	err;

	err = FDF_OK;
	if (map->width <= 0 || map->height <= 0)
		return (FDF_MAP_INVALID_SIZE);
	vb->vertices_count = map->width * map->height;
	vb->vertices = ft_calloc(sizeof(t_fdf_vertex), vb->vertices_count);
	if (!vb->vertices)
		return (FDF_ALLOC_ERROR);
	fdf_vb_fill_vertices(map, vb);
	err = fdf_vb_calculate_edges(vb);
	return (err);
}
