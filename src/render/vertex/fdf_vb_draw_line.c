/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_draw_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:00:57 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/05 08:32:43 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <fdf/render/minilibx.h>
#include <ft/math.h>

t_vec2i	fdf_vec(int32_t x, int32_t y)
{
	t_vec2i	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

static void	fdf_plot(t_vec2i pos, t_mlx_container *data)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= FDF_WINDOW_WIDTH
		|| pos.y >= FDF_WINDOW_HEIGHT)
		return ;
	mlx_set_image_pixel(data->mlx, data->scene, pos.x, pos.y, 0xFFFFFFFF);
}

static void	fdf_plot_low(
		t_fdf_vertex *v1,
		t_fdf_vertex *v2,
		t_mlx_container *data
) {
	t_vec2i	diff;
	t_vec2i	pos;
	int		yi;
	int		d;

	diff = fdf_vec(v2->x - v1->x, v2->y - v1->y);
	yi = 1;
	if (diff.y < 0)
		yi = -1;
	if (diff.y < 0)
		diff.y = -diff.y;
	d = (2 * diff.y) - diff.x;
	pos = fdf_vec(v1->x, v1->y);
	while (pos.x < v2->x)
	{
		fdf_plot(pos, data);
		if (d > 0)
			pos.y += yi;
		if (d > 0)
			d += (2 * (diff.y - diff.x));
		else
			d += 2 * diff.y;
		pos.x++;
	}
}

static void	fdf_plot_high(
		t_fdf_vertex *v1,
		t_fdf_vertex *v2,
		t_mlx_container *data
) {
	t_vec2i	diff;
	t_vec2i	pos;
	int		xi;
	int		d;

	diff = fdf_vec(v2->x - v1->x, v2->y - v1->y);
	xi = 1;
	if (diff.x < 0)
		xi = -1;
	if (diff.x < 0)
		diff.x = -diff.x;
	d = (2 * diff.x) - diff.y;
	pos = fdf_vec(v1->x, v1->y);
	while (pos.y < v2->y)
	{
		fdf_plot(pos, data);
		if (d > 0)
			pos.x += xi;
		if (d > 0)
			d += 2 * (diff.x - diff.y);
		else
			d += 2 * diff.x;
		pos.y++;
	}
}

/**
 * @note Credit: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 */
void	fdf_vb_draw_line(
		t_fdf_vertex *v1,
		t_fdf_vertex *v2,
		t_mlx_container *data
) {
	if (ft_abs(v2->y - v1->y) < ft_abs(v2->x - v1->x))
	{
		if (v1->x > v2->x)
			fdf_plot_low(v2, v1, data);
		else
			fdf_plot_low(v1, v2, data);
	}
	else
	{
		if (v1->y > v2->y)
			fdf_plot_high(v2, v1, data);
		else
			fdf_plot_high(v1, v2, data);
	}
}
