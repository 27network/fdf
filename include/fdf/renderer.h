/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:42:44 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/18 19:45:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include <ft/data/list.h>
# include <stdint.h>

# ifndef FDF_VERTEX_TYPE
#  define FDF_VERTEX_TYPE int32_t
# endif // FDF_VERTEX_TYPE

typedef struct s_fdf_vertex
{
	FDF_VERTEX_TYPE	x;
	FDF_VERTEX_TYPE	y;
	FDF_VERTEX_TYPE	z;
}	t_fdf_point;

typedef struct s_fdf_cuboid
{
	t_list	*vertex_table;
	t_list	*edge_table;
}	t_fdf_cuboid;

#endif // RENDERER_H
