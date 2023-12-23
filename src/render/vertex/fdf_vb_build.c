/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:59:31 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 15:53:08 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <ft/mem.h>

static size_t	fdf_vb_n_edges(t_vertex_buffer *vb)
{
	size_t	n_edges;
	size_t	width;
	size_t	height;

	width = vb->vertices[vb->vertices_count - 1].x + 1;
	height = vb->vertices[vb->vertices_count - 1].y + 1;
	n_edges = vb->vertices_count * 2;
	n_edges -= width + height;
	return (n_edges);
}

static void	fdf_calculate_edges_for(t_vertex_buffer *vb, size_t index,
	size_t *count)
{
	size_t	x;
	size_t	y;
	size_t	max_x;
	size_t	max_y;

	x = vb->vertices[index].x;
	y = vb->vertices[index].y;
	max_x = vb->vertices[vb->vertices_count - 1].x;
	max_y = vb->vertices[vb->vertices_count - 1].y;
	if (x < max_x)
	{
		vb->edges[*count].vertex1 = index;
		vb->edges[*count].vertex2 = index + 1;
		(*count)++;
	}
	if (y < max_y)
	{
		vb->edges[*count].vertex1 = index;
		vb->edges[*count].vertex2 = index + max_x + 1;
		(*count)++;
	}
}

static t_fdf_error	fdf_vb_calculate_edges(t_vertex_buffer *vb)
{
	size_t	count;
	size_t	index;

	vb->edges_count = fdf_vb_n_edges(vb);
	vb->edges = ft_calloc(sizeof(t_fdf_edge), vb->edges_count);
	if (!vb->edges)
		return (FDF_ALLOC_ERROR);
	count = 0;
	index = 0;
	while (index < vb->vertices_count)
	{
		fdf_calculate_edges_for(vb, index, &count);
		index++;
	}
	if (count != vb->edges_count)
		return (FDF_MAP_INVALID_SIZE);
	return (FDF_OK);
}

static void	fdf_vb_fill_vertices(t_map *map, t_vertex_buffer *vb)
{
	size_t			x;
	size_t			y;
	size_t			idx;
	t_fdf_vertex	*vertex;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			idx = y * map->width + x;
			vertex = &vb->vertices[idx];
			vertex->x = x;
			vertex->y = y;
			vertex->z = map->z_matrix[idx];
			vertex->color = fdf_colorpack_int(map->color_matrix[idx]);
			x++;
		}
		y++;
	}
}

t_fdf_error	fdf_vb_build(t_map *map, t_vertex_buffer *vb)
{
	if (map->width <= 0 || map->height <= 0)
		return (FDF_MAP_INVALID_SIZE);
	vb->vertices_count = map->width * map->height;
	vb->vertices = ft_calloc(sizeof(t_fdf_vertex), vb->vertices_count);
	if (!vb->vertices)
		return (FDF_ALLOC_ERROR);
	fdf_vb_fill_vertices(map, vb);
	return (fdf_vb_calculate_edges(vb));
}
