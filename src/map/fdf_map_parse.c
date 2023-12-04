/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:10:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/04 17:02:44 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/map.h>
#include <ft/io.h>
#include <ft/string/parse.h>
#include <ft/string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static size_t	fdf_strcount(char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

static t_fdf_error	fdf_map_parse_size(int fd, t_map *map)
{
	char	*line;
	int		x;
	int		y;

	y = 0;
	while (1)
	{
		line = get_next_line(fd, &line);
		if (!line)
			break ;
		x = fdf_strcount(line, ' ') + 1;
		if (map->width == 0)
			map->width = x;
		else if (map->width != x)
			return (FDF_MAP_INVALID_FILE);
		y++;
		free(line);
	}
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
