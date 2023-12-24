/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_setup_events.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:30:55 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 05:56:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>
#include <ft/print.h>

static int	fdf_wrap_update(void *data)
{
	fdf_mlx_update((t_mlx_container *) data);
	return (0);
}

static int	fdf_wrap_key(int key, void *data)
{
	fdf_mlx_key_pressed(key, (t_mlx_container *) data);
	return (0);
}

static int	fdf_wrap_window(int event, void *data)
{
	fdf_mlx_window_event(event, (t_mlx_container *) data);
	return (0);
}

static int	fdf_wrap_mousewheel(int button, void *data)
{
	if (button == 2)
		((t_mlx_container *) data)->camera->focal_length += 0.1;
	if (button == 1)
		((t_mlx_container *) data)->camera->focal_length -= 0.1;
	return (0);
}

void	fdf_mlx_setup_events(t_mlx_container *data)
{
	mlx_on_event(data->mlx, data->window, MLX_KEYDOWN, fdf_wrap_key, data);
	mlx_on_event(data->mlx, data->window, MLX_WINDOW_EVENT, fdf_wrap_window,
		data);
	mlx_on_event(data->mlx, data->window, MLX_MOUSEWHEEL, fdf_wrap_mousewheel,
		data);
	mlx_loop_hook(data->mlx, fdf_wrap_update, data);
}
