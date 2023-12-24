/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiroussa <oss@xtrm.me>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 01:10:27 by kiroussa          #+#    #+#             */
/*   Updated: 2023/12/24 04:26:36 by kiroussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf/map.h>
#include <ft/io.h>
#include <ft/mem.h>
#include <ft/string/parse.h>
#include <ft/string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * TODO: Add error handling for invalid values for color_matrix parsing
 */
static t_fdf_error	fdf_process_line_val(
		char *value,
		size_t val_idx,
		size_t y,
		t_map *map
) {
	char		**data;
	int			i;
	size_t		t;
	t_fdf_error	error;

	i = -1;
	if (value[ft_strlen(value) - 1] == '\n')
		value[ft_strlen(value) - 1] = 0;
	data = ft_split(value, ',');
	free(value);
	if (!data)
		return (FDF_ALLOC_ERROR);
	error = FDF_OK;
	while (data[++i])
	{
		t = y * map->width + val_idx;
		if (i == 0)
			if (ft_strtoi(data[i], &map->z_matrix[t]) != PARSE_SUCCESS)
				error = FDF_MAP_INVALID_VALUE;
		if (i == 1)
			map->color_matrix[t] = ft_atoi_base(data[i], "0123456789abcdef");
		free(data[i]);
	}
	free(data);
	return (error);
}

static t_fdf_error	fdf_map_fill(int fd, t_map *map)
{
	char		*line;
	char		**arr;
	int			y;
	int			index;
	t_fdf_error	error;

	y = -1;
	error = FDF_OK;
	while (++y != -1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		free(line);
		if (!arr)
			error = FDF_ALLOC_ERROR;
		index = -1;
		while (arr && arr[++index])
			if (fdf_process_line_val(arr[index], index, y, map) != FDF_OK)
				error = FDF_MAP_INVALID_VALUE;
		if (arr)
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
	bool	invalid;

	y = 0;
	invalid = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		if (map->width == 0)
			map->width = fdf_line_size(line);
		else if (!invalid && map->width != fdf_line_size(line))
			invalid = true;
		y++;
		free(line);
	}
	map->height = y;
	if (invalid || map->width <= 1 || map->height <= 1)
		return (FDF_MAP_INVALID_SIZE);
	return (FDF_OK);
}

t_fdf_error	fdf_map_parse(char *file_name, t_map *map)
{
	int			fd;
	t_fdf_error	error;

	if (ft_strlen(file_name) >= 4
		&& ft_strcmp(&file_name[ft_strlen(file_name) - 4], FILE_EXTENSION))
		return (FDF_MAP_INVALID_EXT);
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		return (FDF_MAP_INVALID_FILE);
	error = fdf_map_parse_size(fd, map);
	if (error)
		return (error);
	close(fd);
	map->z_matrix = ft_calloc(map->height * map->width, sizeof(int));
	map->color_matrix = ft_calloc(map->height * map->width, sizeof(int));
	if (!map->z_matrix || !map->color_matrix)
		return (FDF_ALLOC_ERROR);
	fd = open(file_name, O_RDWR);
	if (fd < 0)
		return (FDF_MAP_INVALID_FILE);
	error = fdf_map_fill(fd, map);
	if (error)
		return (error);
	close(fd);
	return (FDF_OK);
}
