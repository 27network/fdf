/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:59 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 15:55:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>

void	*fdf_empty_image(t_mlx_container *data, int width, int height)
{
	void			*img;

	img = mlx_new_image(data->mlx, width, height);
	if (!img)
		return (NULL);
	fdf_clear_image(data, img, width, height);
	return (img);
}

void	fdf_clear_image(t_mlx_container *data, void *img, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_set_image_pixel(data->mlx, img, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
