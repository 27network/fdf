/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_pressed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:35:44 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 02:16:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>

void	fdf_mlx_key_pressed(int keycode, t_mlx_container *data)
{
	if (keycode == 41)
		mlx_loop_end(data->mlx);
}
