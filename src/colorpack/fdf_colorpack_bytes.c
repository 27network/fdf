/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colorpack_bytes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 02:44:33 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/23 02:44:49 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/color.h>

t_colorpack	fdf_colorpack_bytes(uint8_t a, uint8_t r, uint8_t g, uint8_t b)
{
	t_colorpack	pack;

	pack.a = a;
	pack.r = r;
	pack.g = g;
	pack.b = b;
	return (pack);
}
