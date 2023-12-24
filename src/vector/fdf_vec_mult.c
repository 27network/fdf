/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vec_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:42:34 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 04:54:12 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vector.h>

t_vector	fdf_vec_mult(t_vector v, double scalar)
{
	t_vector	v_mult;

	v_mult.x = v.x * scalar;
	v_mult.y = v.y * scalar;
	v_mult.z = v.z * scalar;
	return (v_mult);
}
