/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 00:56:51 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 20:49:31 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

typedef enum e_fdf_error
{
	FDF_OK = 0,
	FDF_ALLOC_ERROR,
	FDF_MAP_INVALID_EXT,
	FDF_MAP_INVALID_SIZE,
	FDF_MAP_PARSE_ERROR,
	FDF_MAP_INVALID_VALUE,
	FDF_MAP_INVALID_FILE,
	FDF_MLX_INIT_FAIL,
	FDF_BAD_CODE
}	t_fdf_error;

char	*fdf_strerror(t_fdf_error err);

#endif // ERROR_H
