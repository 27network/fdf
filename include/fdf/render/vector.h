/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 04:16:05 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 04:54:56 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}	t_vector;

t_vector		fdf_vec_from(double x, double y, double z);

t_vector		fdf_vec_add(t_vector v1, t_vector v2);
t_vector		fdf_vec_sub(t_vector v1, t_vector v2);
t_vector		fdf_vec_mult(t_vector v, double scalar);
t_vector		fdf_vec_div(t_vector v, double scalar);

//double			fdf_vec_dot(t_vector v1, t_vector v2);
double			fdf_vec_length(t_vector v);

//t_vector		fdf_vec_normalize(t_vector v);

//t_vector		fdf_vec_cross(t_vector v1, t_vector v2);

//t_vector		fdf_vec_rot_x(t_vector v, double angle);
//t_vector		fdf_vec_rot_y(t_vector v, double angle);
//t_vector		fdf_vec_rot_z(t_vector v, double angle);

#endif // VECTOR_H
