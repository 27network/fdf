/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 23:06:07 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/19 00:31:42 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>

typedef union u_colorpack
{
	uint32_t	value;
	uint8_t		a;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	uint8_t		argb[4];
}	t_colorpack;

t_colorpack	fdf_colorpack_int(int argv);
t_colorpack	fdf_colorpack_bytes(uint8_t a, uint8_t r, uint8_t g, uint8_t b);

#endif // COLOR_H
