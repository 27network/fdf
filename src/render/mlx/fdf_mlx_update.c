/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:36:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 02:16:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>

void	fdf_mlx_update(t_mlx_container *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img, 1, 1);
}
