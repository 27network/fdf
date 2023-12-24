/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:53:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 05:32:29 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <fdf/defaults.h>
# include <fdf/error.h>
# include <fdf/render/camera.h>
# include <fdf/render/vertex.h>

# include "mlx.h"

typedef struct s_mlx_container
{
	t_vertex_buffer	*vb;
	t_camera		*camera;

	void			*mlx;
	void			*window;
	void			*img;

	double			height_factor;
}	t_mlx_container;

t_fdf_error	fdf_mlx_init(t_vertex_buffer *vb);
void		fdf_mlx_setup_events(t_mlx_container *data);

void		fdf_mlx_update(t_mlx_container *data);
void		fdf_mlx_window_event(int event, t_mlx_container *data);
void		fdf_mlx_key_pressed(int keycode, t_mlx_container *data);

void		*fdf_empty_image(t_mlx_container *data, int width, int height);

#endif // MINILIBX_H
