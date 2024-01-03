/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hud_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:36:54 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/26 18:08:07 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/hud.h>
#include <stdio.h>
#include <stdlib.h>

void	fdf_hud_display(t_mlx_container *data)
{
	static bool		first = true;
	char			*tmp;

	if (first)
	{
		mlx_set_font_scale(data->mlx, data->window, "font.ttf", 24.5);
		first = false;
	}
	mlx_string_put(data->mlx, data->window, 10, 20, 0xFFFFFFFF, "HUD");
	asprintf(&tmp, "Focal length: %f", data->camera->focal_length);
	mlx_string_put(data->mlx, data->window, 10, 40, 0xFFFFFFFF, tmp);
	free(tmp);
	mlx_string_put(data->mlx, data->window, 10, 60, 0xFFFFFFFF, "Camera Pos:");
	asprintf(&tmp, "x: %f", data->camera->position.x);
	mlx_string_put(data->mlx, data->window, 15, 80, 0xFFFFFFFF, tmp);
	free(tmp);
	asprintf(&tmp, "y: %f", data->camera->position.y);
	mlx_string_put(data->mlx, data->window, 15, 100, 0xFFFFFFFF, tmp);
	free(tmp);
	asprintf(&tmp, "z: %f", data->camera->position.z);
	mlx_string_put(data->mlx, data->window, 15, 120, 0xFFFFFFFF, tmp);
	free(tmp);
}
