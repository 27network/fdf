/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:15:32 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 19:08:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <fdf/render/vector.h>
# include <math.h>

typedef struct s_camera
{
	t_vector	position;
	t_vector	direction;
	t_vector	rotation;
	double		focal_length;
}	t_camera;

void	fdf_camera_init(t_camera *camera, int width, int height);

#endif // CAMERA_H
