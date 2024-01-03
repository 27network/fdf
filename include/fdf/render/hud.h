/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 05:37:15 by kiroussa          #+#    #+#             */
/*   Updated: 2024/01/03 15:49:55 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_H
# define HUD_H

# include <fdf/render/minilibx.h>

typedef void	(*t_hud_render)(t_mlx_container *data);
typedef bool	(*t_hud_onclick)(t_mlx_container *data);

typedef struct s_hud_element
{
	t_hud_render			render;
	t_hud_onclick			onclick;
	struct s_hud_element	*children;
}	t_hud_element;

void	fdf_hud_render(t_mlx_container *data);

#endif // HUD_H
