/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:52 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 21:45:48 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>

static t_fdf_error	fdf_kickstart(t_mlx_container *data)
{
	t_fdf_error	err;

	err = FDF_MLX_INIT_FAIL;
	if (data->scene)
	{
		fdf_mlx_setup_events(data);
		mlx_loop(data->mlx);
		mlx_destroy_image(data->mlx, data->scene);
		err = FDF_OK;
	}
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	return (err);
}

t_fdf_error	fdf_mlx_init(t_vertex_buffer *vb)
{
	t_mlx_container	data;
	t_camera		camera;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (FDF_MLX_INIT_FAIL);
	data.window = mlx_new_window(data.mlx, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT,
			PROGRAM_TITLE);
	if (!data.window)
		mlx_destroy_display(data.mlx);
	if (!data.window)
		return (FDF_MLX_INIT_FAIL);
	data.scene = fdf_empty_image(&data, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT);
	data.vb = vb;
	data.height_factor = 1.;
	fdf_camera_init(&camera, FDF_WINDOW_WIDTH, FDF_WINDOW_HEIGHT);
	data.camera = &camera;
	data.is_dirty = true;
	data.width = FDF_WINDOW_WIDTH;
	data.height = FDF_WINDOW_HEIGHT;
	return (fdf_kickstart(&data));
}
