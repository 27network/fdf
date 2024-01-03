/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:53:13 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 17:59:46 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <fdf/defaults.h>
# include <fdf/error.h>
# include <fdf/render/camera.h>
# define FDF_VB_NORENDER
# include <fdf/render/vertex.h>
# undef FDF_VB_NORENDER
# include "mlx.h"

typedef struct s_mlx_container
{
	t_vertex_buffer	*vb;
	t_camera		*camera;

	void			*mlx;
	void			*window;
	int				width;
	int				height;

	void			*scene;
	bool			is_dirty;

	double			height_factor;
}	t_mlx_container;

t_fdf_error	fdf_mlx_init(t_vertex_buffer *vb);
void		fdf_mlx_setup_events(t_mlx_container *data);

void		fdf_mlx_update(t_mlx_container *data);
void		fdf_mlx_window_event(int event, t_mlx_container *data);
void		fdf_mlx_key_pressed(int keycode, t_mlx_container *data);

void		*fdf_empty_image(t_mlx_container *data, int width, int height);
void		fdf_clear_image(t_mlx_container *data, void *img, int width,
				int height);

#endif // MINILIBX_H
