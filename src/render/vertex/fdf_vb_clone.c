/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:47:54 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 20:51:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/error.h>
#include <fdf/render/vertex.h>
#include <ft/mem.h>
#include <stdlib.h>

static void	fdf_vb_clone0(t_vertex_buffer *vb, t_vertex_buffer **clone)
{
	size_t	i;

	i = 0;
	while (i < vb->vertices_count)
	{
		(*clone)->vertices[i].x = vb->vertices[i].x;
		(*clone)->vertices[i].y = vb->vertices[i].y;
		(*clone)->vertices[i].z = vb->vertices[i].z;
		(*clone)->vertices[i].color = vb->vertices[i].color;
		i++;
	}
	i = 0;
	while (i < vb->edges_count)
	{
		(*clone)->edges[i].vertex1 = vb->edges[i].vertex1;
		(*clone)->edges[i].vertex2 = vb->edges[i].vertex2;
		i++;
	}
}

t_fdf_error	fdf_vb_clone(t_vertex_buffer *vb, t_vertex_buffer **clone)
{
	if (!vb || !clone)
		return (FDF_BAD_CODE);
	*clone = ft_calloc(1, sizeof(t_vertex_buffer));
	if (!*clone)
		return (FDF_ALLOC_ERROR);
	(*clone)->vertices_count = vb->vertices_count;
	(*clone)->edges_count = vb->edges_count;
	(*clone)->vertices = ft_calloc(vb->vertices_count, sizeof(t_fdf_vertex));
	if (!(*clone)->vertices)
	{
		free(*clone);
		*clone = NULL;
		return (FDF_ALLOC_ERROR);
	}
	(*clone)->edges = ft_calloc(vb->edges_count, sizeof(t_fdf_edge));
	if (!(*clone)->edges)
	{
		free((*clone)->vertices);
		free(*clone);
		*clone = NULL;
		return (FDF_ALLOC_ERROR);
	}
	fdf_vb_clone0(vb, clone);
	return (FDF_OK);
}
