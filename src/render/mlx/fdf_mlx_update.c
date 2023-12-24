/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:36:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 05:55:35 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/hud.h>
#include <fdf/render/minilibx.h>

void	fdf_mlx_update(t_mlx_container *data)
{
	mlx_clear_window(data->mlx, data->window);
//	mlx_put_image_to_window(data->mlx, data->window, data->img, 1, 1);
	fdf_hud_display(data);
}
