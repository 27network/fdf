/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:36:46 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 16:15:58 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <fdf/render/hud.h>
#include <fdf/render/minilibx.h>
#include <ft/print.h>

void	fdf_mlx_update(t_mlx_container *data)
{
	if (!data->scene_rendered || !data->hud_rendered)
		mlx_clear_window(data->mlx, data->window);
	
		/*
	if (!data->scene_rendered && false)
	{
		ft_printf("Rendering scene...");
		fdf_clear_image(data, data->scene, data->width, data->height);
		fdf_vb_render(data);
		ft_printf(" done!\n");
	}
	mlx_put_image_to_window(data->mlx, data->window, data->scene, 0, 0);
	*/
	if (!data->hud_rendered)
	{
		ft_printf("Rendering hud...");
		fdf_clear_image(data, data->hud, data->width, data->height);
		fdf_hud_render(data);
		ft_printf(" done!\n");
	}
	mlx_put_image_to_window(data->mlx, data->window, data->hud, 0, 0);
}
