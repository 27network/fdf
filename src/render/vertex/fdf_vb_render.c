/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:22:37 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/05 11:05:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <fdf/render/minilibx.h>
#include <fdf/error.h>
#include <ft/math.h>
#include <ft/mem.h>
#include <ft/print.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @note Credits: https://www.youtube.com/watch?v=hFRlnNci3Rs
 */
static void	fdf_transform_vertex(
		t_fdf_vertex *vertex,
		t_camera *camera,
		float focal_length,
		float height_factor
) {
	double	x_projected;
	double	y_projected;

	(void)height_factor;
	(void)camera;
	vertex->x -= camera->position.x;
	vertex->y -= camera->position.y;
	vertex->z -= camera->position.z;
	vertex->z *= 0.01;
	if (focal_length + vertex->z == 0)
		focal_length = 0.00001f;
	x_projected = vertex->x * focal_length / (focal_length + vertex->z);
	y_projected = vertex->y * focal_length / (focal_length + vertex->z);
	x_projected += FDF_WINDOW_WIDTH / 2;
	y_projected += FDF_WINDOW_HEIGHT / 2;
	vertex->x = x_projected;
	vertex->y = y_projected;
}

static t_vertex_buffer	*fdf_vb_apply_transformations(t_mlx_container *data)
{
	t_vertex_buffer	*new;
	size_t			count;
	int				width;
	int				height;

	new = fdf_vb_clone(data->vb);
	if (!new)
		return (NULL);
	width = data->vb->vertices[data->vb->vertices_count - 1].x;
	height = data->vb->vertices[data->vb->vertices_count - 1].y;
	count = 0;
	while (count < new->vertices_count)
	{
		//new->vertices[count].x -= width / 2.;
		//new->vertices[count].y -= height / 2.;
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
	char			*tmp;

	new_buffer = fdf_vb_apply_transformations(data);
	if (!new_buffer)
	{
		ft_dprintf(2, PROGRAM_TITLE": Error while rendering: Allocation error");
		mlx_loop_end(data->mlx);
		return (1);
	}
	v1 = &new_buffer->vertices[0];
	ft_asprintf(&tmp, "draw @ x: %.2f, y: %.2f, z: %.2f", v1->x, v1->y, v1->z);
	mlx_string_put(data->mlx, data->window, 600, 40, 0xFFFFFF, tmp);
	free(tmp);
	edge = 0;
	while (edge++ < new_buffer->edges_count)
	{
		v1 = &new_buffer->vertices[new_buffer->edges[edge - 1].vertex1];
		v2 = &new_buffer->vertices[new_buffer->edges[edge - 1].vertex2];
		fdf_vb_draw_line(v1, v2, data);
	}
	return (0);
}
