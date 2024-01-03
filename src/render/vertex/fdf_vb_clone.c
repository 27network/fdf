/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:47:54 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 13:57:45 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/error.h>
#include <fdf/render/vertex.h>
#include <ft/mem.h>
#include <stdlib.h>

t_vertex_buffer	*fdf_vb_clone(t_vertex_buffer *old)
{
	t_vertex_buffer	*new;

	new = ft_calloc(sizeof(t_vertex_buffer), 1);
	if (!new)
		return (NULL);
	new->edges = ft_calloc(sizeof(t_fdf_edge), old->edges_count);
	new->vertices = ft_calloc(sizeof(t_fdf_vertex), old->vertices_count);
	if (!new->edges || !new->vertices)
	{
		fdf_vb_free(new);
		free(new);
		return (NULL);
	}
	new->edges_count = old->edges_count;
	new->vertices_count = old->vertices_count;
	ft_memcpy(new->edges, old->edges, new->edges_count * sizeof(t_fdf_edge));
	ft_memcpy(new->vertices, old->vertices,
		new->vertices_count * sizeof(t_fdf_vertex));
	return (new);
}
