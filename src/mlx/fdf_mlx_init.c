/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/19 00:51:08 by kiroussa         ###   ########.fr       */
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

static void	fdf_kickstart(t_mlx_container *data)
{
	if (data->img)
	{
		mlx_on_event(data->mlx, data->window, MLX_KEYDOWN, fdf_wrap_window,
			&data);
		mlx_on_event(data->mlx, data->window, MLX_WINDOW_EVENT, fdf_wrap_key,
			&data);
		mlx_loop_hook(data->mlx, fdf_wrap_update, &data);
		mlx_loop(data->mlx);
	}
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
}

t_fdf_error	fdf_mlx_init(t_map *map)
{
	t_mlx_container	data;
	int				w;
	int				h;

	data.map = map;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (FDF_MLX_INIT_FAIL);
	mlx_get_screens_size(data.mlx, &w, &h);
	if (h <= 0 || w <= 0)
		mlx_destroy_display(data.mlx);
	if (h <= 0 || w <= 0)
		return (FDF_MLX_INIT_FAIL);
	data.window = mlx_new_window(data.mlx, w, h, PROGRAM_TITLE);
	if (!data.window)
		mlx_destroy_display(data.mlx);
	if (!data.window)
		return (FDF_MLX_INIT_FAIL);
	data.img = fdf_empty_image(&data, w, h);
	data.height_factor = 1.;
	fdf_kickstart(&data);
	return (FDF_OK);
}
