/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:42:30 by kiroussa          #+#    #+#             */
/*   Updated: 2023/10/31 03:32:20 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PROGRAM_TITLE "so_long"

# include <ft/error.h>
# include <ft/string/parse.h>
# include <ft/string.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	size_t	width;
	size_t	height;
	t_list	*contents;
}	t_map;

/* Map Parsing */
t_error	ft_parse_map(t_map *map, char *file_path);

#endif // SO_LONG_H
