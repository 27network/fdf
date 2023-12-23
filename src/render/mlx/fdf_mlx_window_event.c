/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_window_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:31:18 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 02:16:52 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>

void	fdf_mlx_window_event(int event, t_mlx_container *data)
{
	if (event == 0)
		mlx_loop_end(data->mlx);
}
