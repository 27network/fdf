/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:56:51 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/03 01:13:53 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_fdf_error
{
	FDF_OK = 0,
	FDF_MAP_INVALID_SIZE,
	FDF_MAP_INVALID_Z_VALUE,
	FDF_MAP_INVALID_COLOR_VALUE,
	FDF_MAP_INVALID_FILE,
	FDF_MLX_INIT_FAIL
}	t_fdf_error;

t_fdf_error	fdf_ok(void);

#endif // ERROR_H
