/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_strerror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:40:19 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 04:22:32 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/error.h>
#include <string.h>
#include <errno.h>

char	*fdf_strerror(t_fdf_error err)
{
	static char	*errors[] = {
	[FDF_OK] = "OK",
	[FDF_ALLOC_ERROR] = "Allocation error",
	[FDF_MAP_INVALID_EXT] = "Invalid extension",
	[FDF_MAP_INVALID_SIZE] = "Invalid size",
	[FDF_MAP_PARSE_ERROR] = "Parsing error",
	[FDF_MAP_INVALID_VALUE] = "Invalid value",
	[FDF_MLX_INIT_FAIL] = "MLX died, as usual"
	};

	if (err == FDF_MAP_INVALID_FILE)
		return (strerror(errno));
	return (errors[err]);
}
