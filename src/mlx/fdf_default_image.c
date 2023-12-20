/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_default_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:33:59 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/20 12:03:15 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/minilibx.h>
#include <stdio.h>

void	*fdf_empty_image(t_mlx_container *data, int width, int height)
{
	void			*img;
	int				x;
	int				y;
	unsigned char	pixels[4];

	img = mlx_new_image(data->mlx, width, height);
	if (!img)
		return (NULL);
	pixels[0] = 0;
	pixels[1] = 0;
	pixels[2] = 0;
	pixels[3] = 0x99;
	x = 0;
	y = 0;
	printf("w: %d h: %d\n", width, height);
	while (y < height)
	{
		while (x < width)
		{
			mlx_set_image_pixel(data->mlx, img, x, y, *((int *)pixels));
			x++;
		}
		y++;
	}
	return (img);
}
