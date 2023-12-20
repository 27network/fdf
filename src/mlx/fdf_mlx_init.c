/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 15:33:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/minilibx.h>

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

static t_fdf_error	fdf_kickstart(t_mlx_container *data)
{
	t_fdf_error	err;

	err = FDF_MLX_INIT_FAIL;
	if (data->img)
	{
		mlx_on_event(data->mlx, data->window, MLX_KEYDOWN,
			fdf_wrap_key, data);
		mlx_on_event(data->mlx, data->window, MLX_WINDOW_EVENT,
			fdf_wrap_window, data);
		mlx_loop_hook(data->mlx, fdf_wrap_update, data);
		mlx_loop(data->mlx);
		mlx_destroy_image(data->mlx, data->img);
		err = FDF_OK;
	}
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	return (err);
}

t_fdf_error	fdf_mlx_init(t_map *map)
{
	t_mlx_container	data;

	data.map = map;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (FDF_MLX_INIT_FAIL);
	data.window = mlx_new_window(data.mlx, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT,
			PROGRAM_TITLE);
	if (!data.window)
		mlx_destroy_display(data.mlx);
	if (!data.window)
		return (FDF_MLX_INIT_FAIL);
	data.img = fdf_empty_image(&data, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT);
	data.height_factor = 1.;
	return (fdf_kickstart(&data));
}
