/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:35:44 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 05:28:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>
#include <SDL2/SDL_scancode.h>

void	fdf_mlx_key_pressed(int keycode, t_mlx_container *data)
{
	if (keycode == SDL_SCANCODE_ESCAPE)
		mlx_loop_end(data->mlx);
	if (keycode == SDL_SCANCODE_UP)
		data->camera->focal_length += 1;
	if (keycode == SDL_SCANCODE_DOWN)
		data->camera->focal_length -= 1;
}
