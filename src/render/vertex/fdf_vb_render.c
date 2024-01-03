/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:22:37 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 15:42:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <fdf/render/minilibx.h>
#include <fdf/error.h>
#include <ft/mem.h>
#include <ft/print.h>

/**
 * @note Credits: https://www.youtube.com/watch?v=hFRlnNci3Rs
 */
static void	fdf_transform_vertex(
		t_fdf_vertex *vertex,
		t_camera *camera,
		float focal_length,
		float height_factor
) {
	int			x_projected;
	int			y_projected;

	(void)camera;
	vertex->z *= height_factor;
	x_projected = (focal_length * vertex->x);
	x_projected /= focal_length + vertex->z;
	y_projected = (focal_length * vertex->y);
	y_projected /= focal_length + vertex->z;
	vertex->x = x_projected;
	vertex->y = y_projected;
}

static t_vertex_buffer	*fdf_vb_apply_transformations(t_mlx_container *data)
{
	t_vertex_buffer	*new;
	size_t			count;

	new = fdf_vb_clone(data->vb);
	if (!new)
		return (NULL);
	count = 0;
	while (count < new->vertices_count)
	{
		fdf_transform_vertex(
			&(new->vertices[count]),
			data->camera,
			data->camera->focal_length,
			data->height_factor);
		count++;
	}
	return (new);
}

int	fdf_vb_render(t_mlx_container *data)
{
	t_vertex_buffer	*new_buffer;
	size_t			edge;
	t_fdf_vertex	*v1;
	t_fdf_vertex	*v2;

	new_buffer = fdf_vb_apply_transformations(data);
	if (!new_buffer)
	{
		ft_dprintf(2, PROGRAM_TITLE": Error while rendering: %s",
			fdf_strerror(FDF_ALLOC_ERROR));
		mlx_loop_end(data->mlx);
		return (1);
	}
	edge = 0;
	while (edge < new_buffer->edges_count)
	{
		v1 = &new_buffer->vertices[new_buffer->edges[edge].vertex1];
		v2 = &new_buffer->vertices[new_buffer->edges[edge].vertex2];
		fdf_vb_draw_line(v1, v2, data);
		edge++;
	}
	data->scene_rendered = true;
	return (0);
}
