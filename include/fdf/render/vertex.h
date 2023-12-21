/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:42:44 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/22 00:12:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include <fdf/color.h>
# include <fdf/error.h>
# include <fdf/map.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_fdf_vertex
{
	uint32_t	x;
	uint32_t	y;
	int32_t		z;
	t_colorpack	color;
}	t_fdf_vertex;

typedef struct s_fdf_edge
{
	size_t	vertex1;
	size_t	vertex2;
}	t_fdf_edge;

typedef struct s_fdf_vertex_buffer
{
	t_fdf_vertex	*vertices;
	size_t			vertices_count;
	t_fdf_edge		*edges;
	size_t			edges_count;
}	t_vertex_buffer;

t_fdf_error	fdf_vb_build(t_map *map, t_vertex_buffer *vb);
t_fdf_error	fdf_vb_calculate_edges(t_vertex_buffer *vb);
void		fdf_vb_free(t_vertex_buffer *vb);

#endif // VERTEX_H
