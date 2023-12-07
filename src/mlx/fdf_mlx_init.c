/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:52 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/07 15:50:41 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft/print.h>
#include <fdf/minilibx.h>

void	fdf_mlx_init(t_map *map)
{
	t_mlx_container	data;

	(void)map;
	ft_printf("mlx_init()\n");
	data.mlx = mlx_init();
	ft_printf("mlx_new_window(%p, 400, 400, \"fdf\")\n", data.mlx);
	data.window = mlx_new_window(data.mlx, 400, 400, PROGRAM_TITLE);
	ft_printf("mlx_destroy_window(%p, %p)\n", data.mlx, data.window);
	mlx_destroy_window(data.mlx, data.window);
	ft_printf("mlx_destroy_display(%p)\n", data.mlx);
	mlx_destroy_display(data.mlx);
	ft_printf("done.\n");
}
