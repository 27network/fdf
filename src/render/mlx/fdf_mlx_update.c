/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:36:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 12:00:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/minilibx.h>

void	fdf_mlx_update(t_mlx_container *data)
{
	mlx_put_image_to_window(data->mlx, data->window, data->img, 1, 1);
}
