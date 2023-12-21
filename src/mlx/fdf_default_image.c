/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:59 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 19:45:22 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/minilibx.h>

void	*fdf_empty_image(t_mlx_container *data, int width, int height)
{
	void			*img;
	int				x;
	int				y;
	int				color;

	img = mlx_new_image(data->mlx, width, height);
	if (!img)
		return (NULL);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			color = 0xFF0000FF;
			if (x >= width / 2 && y >= height / 2)
				color = 0xFF00FF00;
			mlx_set_image_pixel(data->mlx, img, x, y, color);
			x++;
		}
		y++;
	}
	return (img);
}
