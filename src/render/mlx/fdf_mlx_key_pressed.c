/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:35:44 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 15:54:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>
#include <SDL2/SDL_scancode.h>

void	fdf_mlx_key_pressed(int scancode, t_mlx_container *data)
{
	if (scancode == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->mlx);
	else if (scancode == SDL_SCANCODE_UP)
		data->camera->focal_length += 1;
	else if (scancode == SDL_SCANCODE_DOWN)
		data->camera->focal_length -= 1;
	else
		return ;
	data->hud_rendered = false;
	data->scene_rendered = false;
}
