/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:53:13 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/07 15:17:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include <fdf/map.h>

# include "mlx.h"

typedef struct s_mlx_container
{
	void	*mlx;
	void	*window;
}	t_mlx_container;

void	fdf_mlx_init(t_map *map);

#endif // MINILIBX_H
