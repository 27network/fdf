/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:10:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/06 23:13:40 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/map.h>
#include <ft/io.h>
#include <ft/mem.h>
#include <ft/print.h>
#include <ft/string/parse.h>
#include <ft/string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static t_fdf_error	fdf_process_line_val(
		char *value,
		size_t val_idx,
		size_t y,
		t_map *map
) {
	char		**data;
	size_t		index;
	size_t		target_idx;
	t_fdf_error	error;

	index = 0;
	data = ft_split(value, ',');
	free(value);
	error = FDF_OK;
	while (data[index])
	{
		target_idx = y * map->width + val_idx;
		if (index == 0)
			if (ft_strtoi(data[index], &map->z_matrix[target_idx])
				!= PARSE_SUCCESS)
				error = FDF_MAP_INVALID_Z_VALUE;
		if (index == 1)
			map->color_matrix[y * map->width + val_idx]
				= ft_atoi_base(data[index], "0123456789abcdef");
		free(data[index]);
		index++;
	}
	free(data);
	return (error);
}

static t_fdf_error	fdf_map_fill(int fd, t_map *map)
{
	char		*line;
	char		**arr;
	size_t		y;
	size_t		index;
	t_fdf_error	error;

	y = 0;
	error = FDF_OK;
	while (error == FDF_OK)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		free(line);
		if (!arr)
			error = FDF_ALLOC_ERROR;
		if (error)
			return (error);
		index = 0;
		while (arr[index])
			error = fdf_process_line_val(arr[index], index, y, map);
		free(arr);
	}
	return (error);
}

static size_t	fdf_line_size(char *line)
{
	size_t	count;
	char	**tab;

	count = 0;
	tab = ft_split(line, ' ');
	while (tab[count])
	{
		free(tab[count]);
		count++;
	}
	free(tab);
	return (count);
}

static t_fdf_error	fdf_map_parse_size(int fd, t_map *map)
{
	char	*line;
	size_t	y;

	y = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		if (map->width == 0)
			map->width = fdf_line_size(line);
		else if (map->width != fdf_line_size(line))
			return (FDF_MAP_INVALID_SIZE);
		y++;
		free(line);
	}
	map->height = y;
	map->z_matrix = ft_calloc(map->height * map->width, sizeof(int));
	map->color_matrix = ft_calloc(map->height * map->width, sizeof(int));
	if (!map->z_matrix || !map->color_matrix)
		return (FDF_ALLOC_ERROR);
	return (FDF_OK);
}

t_fdf_error	fdf_map_parse(char *file_name, t_map *map)
{
	int			fd;
	t_fdf_error	error;

	if (ft_strlen(file_name) >= 4
		&& ft_strcmp(&file_name[ft_strlen(file_name) - 4], FILE_EXTENSION))
		return (FDF_MAP_INVALID_EXT);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (FDF_MAP_INVALID_FILE);
	error = fdf_map_parse_size(fd, map);
	if (error)
		return (error);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (FDF_MAP_INVALID_FILE);
	error = fdf_map_fill(fd, map);
	if (error)
		return (error);
	close(fd);
	return (FDF_OK);
}
