/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_camera_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:47:48 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 04:55:02 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/camera.h>

void	fdf_camera_init(t_camera *camera)
{
	camera->position = fdf_vec_from(0, 0, 0);
	camera->direction = fdf_vec_from(0, 0, 1);
	camera->rotation = fdf_vec_from(0, 0, 0);
	camera->focal_length = 10;
}
