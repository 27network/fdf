/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:10:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/03 01:16:54 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/map.h>
#include <ft/string/parse.h>
#include <ft/string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static t_fdf_error	fdf_map_parse_size(int fd, t_map *map)
{
	char	*line;
	int		ret;
	int		x;
	int		y;

	y = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		x = 0;
		while (line[x])
		{
			if (ft_isdigit(line[x]))
				x++;
			else
				return (FDF_MAP_INVALID_Z_VALUE);
		}
		if (map->width == 0)
			map->width = x;
		else if (map->width != x)
			return (FDF_MAP_INVALID_SIZE);
		y++;
		free(line);
	}
	if (ret < 0)
		return (FDF_MAP_INVALID_FILE);
	map->height = y;
	return (fdf_ok());
}

t_fdf_error	fdf_map_parse(char *file_name, t_map *map)
{
	int			fd;
	t_fdf_error	error;

	map->width = 0;
	map->height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (FDF_MAP_INVALID_FILE);
	error = fdf_map_parse_size(fd, map);
	if (error)
		return (error);
	close(fd);
	return (fdf_ok());
}
