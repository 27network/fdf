/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vb_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:58:14 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 14:57:03 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <stdlib.h>

void	fdf_vb_free(t_vertex_buffer *vb)
{
	if (!vb)
		return ;
	if (vb->vertices)
		free(vb->vertices);
	if (vb->edges)
		free(vb->edges);
}
