/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_setup_events.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:30:55 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 22:02:44 by kiroussa         ###   ########.fr       */
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

static int	fdf_wrap_mousewheel(int button, void *d)
{
	t_mlx_container	*data;

	data = (t_mlx_container *) d;
	if (button == 2)
		data->camera->focal_length -= 0.1;
	else if (button == 1)
		data->camera->focal_length += 0.1;
	else
		return (0);
	data->is_dirty = true;
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
