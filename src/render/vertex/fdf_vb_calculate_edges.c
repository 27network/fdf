/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_calculate_edges.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 23:45:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/22 00:13:39 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>

static size_t	fdf_vb_n_edges_for(t_vertex_buffer *vb)
{
	(void)vb;
}

static size_t	fdf_vb_n_edges(t_vertex_buffer *vb)
{
	(void)vb;
}

t_fdf_error	fdf_vb_calculate_edges(t_vertex_buffer *vb)
{
	t_fdf_error	err;

	(void)vb;
	err = FDF_OK;
	return (err);
}
