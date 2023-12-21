/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_vertex_buffer_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:58:14 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/21 22:59:23 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/render/vertex.h>
#include <stdlib.h>

void	fdf_vertex_buffer_free(t_vertex_buffer *vb)
{
	free(vb->vertices);
	free(vb->edges);
}
