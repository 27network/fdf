/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:35:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/05 08:34:26 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>
#include <SDL2/SDL_scancode.h>

void	fdf_mlx_key_pressed(int scancode, t_mlx_container *data)
{
	if (scancode == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->mlx);
	else if (scancode == SDL_SCANCODE_DOWN)
		data->camera->focal_length += .125;
	else if (scancode == SDL_SCANCODE_UP)
	{
		data->camera->focal_length -= .125;
		if (data->camera->focal_length < 0)
			data->camera->focal_length = 0;
	}
	else if (scancode == SDL_SCANCODE_W)
		data->camera->position.y += 2.5;
	else if (scancode == SDL_SCANCODE_S)
		data->camera->position.y -= 2.5;
	else if (scancode == SDL_SCANCODE_D)
		data->camera->position.x -= 2.5;
	else if (scancode == SDL_SCANCODE_A)
		data->camera->position.x += 2.5;
	else if (scancode == SDL_SCANCODE_F)
		data->camera->position.z += 0.5;
	else if (scancode == SDL_SCANCODE_R)
		data->camera->position.z -= 0.5;
	else if (scancode == SDL_SCANCODE_P)
		data->height_factor += .001;
	else if (scancode == SDL_SCANCODE_O)
		data->height_factor -= .001;
	else
		return ;
	data->is_dirty = true;
}
