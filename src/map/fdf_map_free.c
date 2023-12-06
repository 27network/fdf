/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:08:10 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/06 17:19:14 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/map.h>
#include <stdlib.h>

void	fdf_map_free(t_map *map)
{
	if (map->z_matrix)
		free(map->z_matrix);
	if (map->color_matrix)
		free(map->color_matrix);
}
