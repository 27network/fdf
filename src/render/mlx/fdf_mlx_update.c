/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:36:46 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 20:40:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/defaults.h>
#include <fdf/error.h>
#include <fdf/render/hud.h>
#include <fdf/render/minilibx.h>
#include <ft/mem.h>
#include <ft/print.h>
#include <stdlib.h>

//TODO: apply camera transforms
static t_vertex_buffer	*fdf_transform(t_vertex_buffer *vb)
{
	t_vertex_buffer	*new_vb;

	new_vb = ft_calloc(1, sizeof(t_vertex_buffer));
	if (fdf_vb_clone(vb, new_vb) != FDF_OK)
		return (NULL);
	return (new_vb);
}

void	fdf_mlx_update(t_mlx_container *data)
{
	t_vertex_buffer	*new_vb;

	new_vb = fdf_transform(data->vb);
	if (new_vb == NULL)
	{
		mlx_loop_end(data->mlx);
		ft_dprintf(2, PROGRAM_TITLE": %s\n", fdf_strerror(FDF_ALLOC_ERROR));
	}
	free(new_vb);
	mlx_clear_window(data->mlx, data->window);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 1, 1);
	fdf_hud_display(data);
}
