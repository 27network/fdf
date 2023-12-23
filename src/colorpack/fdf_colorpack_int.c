/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colorpack_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:43:53 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 02:44:26 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/color.h>

t_colorpack	fdf_colorpack_int(int color)
{
	t_colorpack	pack;

	pack.value = (uint32_t)color;
	return (pack);
}
