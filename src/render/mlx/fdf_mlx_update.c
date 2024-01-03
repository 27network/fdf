/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:36:46 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 23:49:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <fdf/render/hud.h>
#include <fdf/render/minilibx.h>
#include <ft/print.h>
#include <stdlib.h>
#include <stdio.h>

__attribute__((unused))
static void	render_debug(t_mlx_container *data)
{
	t_fdf_vertex	v1;
	t_fdf_vertex	v2;

	v1.x = 0;
	v1.y = FDF_WINDOW_HEIGHT / 2;
	v2.x = FDF_WINDOW_WIDTH;
	v2.y = FDF_WINDOW_HEIGHT / 2;
	fdf_vb_draw_line(&v1, &v2, data);
	v1.x = FDF_WINDOW_WIDTH / 2;
	v1.y = 0;
	v2.x = FDF_WINDOW_WIDTH / 2;
	v2.y = FDF_WINDOW_HEIGHT;
	fdf_vb_draw_line(&v1, &v2, data);
}

__attribute__((unused))
static void	render_debug2(t_mlx_container *data)
{
	t_vertex_buffer	*vb;

	vb = malloc(sizeof(t_vertex_buffer));
	vb->vertices_count = 8;
	vb->vertices = malloc(sizeof(t_fdf_vertex) * vb->vertices_count);
	vb->vertices[0].x = 63.;
	vb->vertices[0].y = 63.;
	vb->vertices[0].z = 63.;
	vb->vertices[1].x = 63.;
	vb->vertices[1].y = -63.;
	vb->vertices[1].z = 63.;
	vb->vertices[2].x = -63.;
	vb->vertices[2].y = -63.;
	vb->vertices[2].z = 63.;
	vb->vertices[3].x = -63.;
	vb->vertices[3].y = 63.;
	vb->vertices[3].z = 63.;
	vb->vertices[4].x = 63.;
	vb->vertices[4].y = 63.;
	vb->vertices[4].z = -63.;
	vb->vertices[5].x = 63.;
	vb->vertices[5].y = -63.;
	vb->vertices[5].z = -63.;
	vb->vertices[6].x = -63.;
	vb->vertices[6].y = -63.;
	vb->vertices[6].z = -63.;
	vb->vertices[7].x = -63.;
	vb->vertices[7].y = 63.;
	vb->vertices[7].z = -63.;
	vb->edges_count = 12;
	vb->edges = (t_fdf_edge *)malloc(sizeof(t_fdf_edge) * vb->edges_count);
	vb->edges[0].vertex1 = 0;
	vb->edges[0].vertex2 = 1;
	vb->edges[1].vertex1 = 1;
	vb->edges[1].vertex2 = 2;
	vb->edges[2].vertex1 = 2;
	vb->edges[2].vertex2 = 3;
	vb->edges[3].vertex1 = 3;
	vb->edges[3].vertex2 = 0;
	vb->edges[4].vertex1 = 4;
	vb->edges[4].vertex2 = 5;
	vb->edges[5].vertex1 = 5;
	vb->edges[5].vertex2 = 6;
	vb->edges[6].vertex1 = 6;
	vb->edges[6].vertex2 = 7;
	vb->edges[7].vertex1 = 7;
	vb->edges[7].vertex2 = 4;
	vb->edges[8].vertex1 = 0;
	vb->edges[8].vertex2 = 4;
	vb->edges[9].vertex1 = 1;
	vb->edges[9].vertex2 = 5;
	vb->edges[10].vertex1 = 2;
	vb->edges[10].vertex2 = 6;
	vb->edges[11].vertex1 = 3;
	vb->edges[11].vertex2 = 7;
	t_vertex_buffer	*old;
	old = data->vb;
	data->vb = vb;
	printf("fuck %p %p\n", vb->vertices, data->vb->vertices);
	fdf_vb_render(data);
	data->vb = old;
}

void	fdf_mlx_update(t_mlx_container *data)
{
	if (data->is_dirty)
	{
		ft_printf("Clearing!\n");
		mlx_clear_window(data->mlx, data->window);
		ft_printf("Rendering scene...");
		fdf_clear_image(data, data->scene, data->width, data->height);
//		fdf_vb_render(data);
		render_debug2(data);
		render_debug(data);
		mlx_put_image_to_window(data->mlx, data->window, data->scene, 0, 0);
		ft_printf(" done!\n");
		ft_printf("Rendering hud...");
		fdf_hud_render(data);
		ft_printf(" done!\n");
		data->is_dirty = false;
	}
}
