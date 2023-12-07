/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/07 15:38:57 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/minilibx.h>

void	fdf_mlx_init(t_map *map)
{
	t_mlx_container	data;

	(void)map;
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 400, 400, PROGRAM_TITLE);
	mlx_destroy_window(data.mlx, data.window);
	mlx_destroy_display(data.mlx);
}
