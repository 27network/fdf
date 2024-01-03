/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hud_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:36:54 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 22:13:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/hud.h>
#include <ft/print.h>
#include <stdlib.h>

static void	fdf_draw_string(char *string, int x, int y, t_mlx_container *data)
{
	mlx_string_put(data->mlx, data->window, x, y, 0xFFFFFFFF, string);
}

void	fdf_hud_render(t_mlx_container *data)
{
	static bool		first = false;
	char			*tmp;

	if (first)
	{
		mlx_set_font_scale(data->mlx, data->window, "font.ttf", 24.5);
		first = false;
	}
	fdf_draw_string("HUD", 10, 20, data);
	ft_asprintf(&tmp, "Focal length: %f", data->camera->focal_length);
	fdf_draw_string(tmp, 10, 40, data);
	free(tmp);
	fdf_draw_string("Camera Pos:", 10, 60, data);
	ft_asprintf(&tmp, "x: %f", data->camera->position.x);
	fdf_draw_string(tmp, 10, 80, data);
	free(tmp);
	ft_asprintf(&tmp, "y: %f", data->camera->position.y);
	fdf_draw_string(tmp, 10, 100, data);
	free(tmp);
	ft_asprintf(&tmp, "z: %f", data->camera->position.z);
	fdf_draw_string(tmp, 10, 120, data);
	free(tmp);
	ft_asprintf(&tmp, "First vertex: %.1f %.1f %.1f", data->vb->vertices[0].x, data->vb->vertices[0].y, data->vb->vertices[0].z);
	fdf_draw_string(tmp, 10, 140, data);
	free(tmp);
	ft_asprintf(&tmp, "Height factor: %f", data->height_factor);
	fdf_draw_string(tmp, 10, 160, data);
	free(tmp);
}
