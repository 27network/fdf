/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:59 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 15:45:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/minilibx.h>

void	*fdf_empty_image(t_mlx_container *data, int width, int height)
{
	void			*img;
	int				x;
	int				y;

	img = mlx_new_image(data->mlx, width, height);
	if (!img)
		return (NULL);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_set_image_pixel(data->mlx, img, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
	return (img);
}
