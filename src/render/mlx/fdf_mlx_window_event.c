/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_window_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:31:18 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/18 19:31:51 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/minilibx.h>

void	fdf_mlx_window_event(int event, t_mlx_container *data)
{
	if (event == 0)
		mlx_loop_end(data->mlx);
}
