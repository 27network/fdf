/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:55:03 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/03 01:11:10 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fdf/defaults.h>
# include <fdf/error.h>

/**
 * @brief	Map structure. 
 * @note	We store map data (z and color matrix) as 1d unfoldable arrays.
 */
typedef struct s_map
{
	size_t	width;
	size_t	height;
	int		*z_matrix;
	int		*color_matrix;
}	t_map;

t_fdf_error	fdf_map_parse(char *file_name, t_map *map);
void		fdf_map_free(t_map *map);

#endif // MAP_H
