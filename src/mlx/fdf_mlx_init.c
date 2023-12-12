/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/12 15:18:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <fdf/minilibx.h>

static int	fdf_mlx_update(void *data)
{
	(void)data;
	return (0);
}

static int	fdf_mlx_on_key(int key, void *data)
{
	if (key == 41)
		mlx_loop_end(((t_mlx_container *) data)->mlx);
	return (0);
}

static int	fdf_mlx_on_event(int event, void *data)
{
	if (event == 0)
		mlx_loop_end(((t_mlx_container *) data)->mlx);
	return (0);
}

void	fdf_mlx_init(t_map *map)
{
	t_mlx_container	data;

	(void)map;
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 400, 400, PROGRAM_TITLE);
	mlx_on_event(data.mlx, data.window, MLX_KEYDOWN, fdf_mlx_on_key, &data);
	mlx_on_event(data.mlx, data.window, MLX_WINDOW_EVENT, fdf_mlx_on_event,
		&data);
	mlx_loop_hook(data.mlx, fdf_mlx_update, &data);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
}
