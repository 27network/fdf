/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vec_div.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:42:44 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 04:54:18 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vector.h>

t_vector	fdf_vec_div(t_vector v, double scalar)
{
	t_vector	v_div;

	v_div.x = v.x / scalar;
	v_div.y = v.y / scalar;
	v_div.z = v.z / scalar;
	return (v_div);
}
