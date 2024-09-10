/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:48:04 by sbruma            #+#    #+#             */
/*   Updated: 2024/09/10 19:35:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

uint32_t hex_to_uint(char *hex)
{
    uint32_t color;
    char *base_chars;
	int len;

	base_chars = "0123456789ABCDEF";
	color = 0;
	hex += 2;
	len = ft_strlen(hex);
    while (--len >= 0)
        color = color * 16 + (ft_strchr(base_chars, ft_toupper(*hex)) - base_chars);
	// color |= 0xFF000000;
    return (color);
}

// Updated parse_point function with default color handling
void parse_point(char *str, t_map *map, int x, int y)
{
    char **parts;
    int z;
    uint32_t color;

    parts = ft_split(str, ',');
    z = ft_atoi(parts[0]);
    if (parts[1])
        color = hex_to_uint(parts[1]);
    else
        color = 0xFFFFFFFF;
	// color |= 0xFF000000;
    map->x = x;
    map->y = y;
    map->z = z;
    map->color = color;
    free_split(parts);
}

void	fill_map(int fd, t_fdf *ptr)
{
	char	*line;
	char	**split_line;
	int		x;
	int		y;
	int		len;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		len= ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		split_line = ft_split(line, ' ');
		x = 0;
		while (split_line[x] != NULL)
		{
			if (y < ptr->height && x < ptr->width)
				parse_point(split_line[x], &ptr->map[y * ptr->width + x], x, y);
			x++;
		}
		y++;
		free(line);
		free_split(split_line);
		line = get_next_line(fd);
	}
}

void	allocate_map_memory(t_fdf *ptr)
{
	ptr->map = (t_map *)malloc_t_bad(sizeof(t_map) * (ptr->width * ptr->height));
	if (!ptr->map)
		error("Memory allocation failed\n");
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free_t_bad(split[i]);
		i++;
	}
	free_t_bad(split);
}

void	read_map_dimensions(int fd, t_fdf *ptr)
{
	char	*line;
	char	**split_line;

	ptr->height = 0;
	ptr->width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		split_line = ft_split(line, ' ');
		if (ptr->height == 0)
			while (split_line[ptr->width])
				ptr->width++;
		ptr->height++;
		free_t_bad(line);
		free_split(split_line);
		line = get_next_line(fd);
	}
}

void	init_fdf(char *path, t_fdf *ptr)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("Failed to open file\n");
	read_map_dimensions(fd, ptr);
	close(fd);
	allocate_map_memory(ptr);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error("Failed to open file\n");
	fill_map(fd, ptr);
	close(fd);
}
