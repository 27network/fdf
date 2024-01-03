/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:42:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 15:28:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTEX_H
# define VERTEX_H

# include <fdf/render/camera.h>
# include <fdf/color.h>
# include <fdf/error.h>
# include <fdf/map.h>
# include <stddef.h>
# include <stdint.h>

typedef struct s_fdf_vertex
{
	int32_t		x;
	int32_t		y;
	int32_t		z;
	t_colorpack	color;
}	t_fdf_vertex;

typedef struct s_fdf_edge
{
	size_t	vertex1;
	size_t	vertex2;
}	t_fdf_edge;

typedef struct s_vertex_buffer
{
	t_fdf_vertex	*vertices;
	size_t			vertices_count;
	t_fdf_edge		*edges;
	size_t			edges_count;
}	t_vertex_buffer;

t_fdf_error		fdf_vb_build(t_map *map, t_vertex_buffer *vb);
void			fdf_vb_free(t_vertex_buffer *vb);
t_vertex_buffer	*fdf_vb_clone(t_vertex_buffer *vb);

# ifndef FDF_VB_NORENDER

typedef struct s_mlx_container	t_mlx_container;
int				fdf_vb_render(t_mlx_container *data);
void			fdf_vb_draw_line(t_fdf_vertex *v1, t_fdf_vertex *v2,
					t_mlx_container *data);

# endif // FDF_VB_NORENDER

typedef struct s_vec2i
{
	int32_t	x;
	int32_t	y;
}	t_vec2i;

t_vec2i			fdf_vec(int32_t x, int32_t y);

#endif // VERTEX_H
