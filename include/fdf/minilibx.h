/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:53:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/19 00:41:31 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <fdf/error.h>
# include <fdf/map.h>

# include "mlx.h"

typedef struct s_mlx_container
{
	t_map	*map;

	void	*mlx;
	void	*window;
	void	*img;

	double	height_factor;
}	t_mlx_container;

void		fdf_mlx_update(t_mlx_container *data);
void		fdf_mlx_window_event(int event, t_mlx_container *data);
void		fdf_mlx_key_pressed(int keycode, t_mlx_container *data);
t_fdf_error	fdf_mlx_init(t_map *map);

void		*fdf_empty_image(t_mlx_container *data, int width, int height);

#endif // MINILIBX_H
