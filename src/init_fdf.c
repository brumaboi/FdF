/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:48:04 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 17:10:15 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	read_fdf(char *path, t_fdf *ptr)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**split;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		split = ft_split(line, ' ');
		j = 0;
		while (split[j])
		{
			ptr->map[i * ptr->width + j].x = j;
			ptr->map[i * ptr->width + j].y = i;
			ptr->map[i * ptr->width + j].z = ft_atoi(split[j]);
			if (i == 0 && j == 0)
			{
				ptr->map[i * ptr->width + j].max_z = ptr->map[i * ptr->width + j].z;
				ptr->map[i * ptr->width + j].min_z = ptr->map[i * ptr->width + j].z;
			}
			else
			{
				if (ptr->map[i * ptr->width + j].z > ptr->map[0].max_z)
					ptr->map[0].max_z = ptr->map[i * ptr->width + j].z;
				if (ptr->map[i * ptr->width + j].z < ptr->map[0].min_z)
					ptr->map[0].min_z = ptr->map[i * ptr->width + j].z;
			}
			j++;
		}
		for (int k = 0; split[k]; k++)
			free(split[k]);
		free(split);
		free(line);
		i++;
	}
	close(fd);
}

static void	set_sizes(char *path, t_fdf *ptr)
{
	int		fd;
	char	*line;
	int		width;
	int		height;
	int		current_width;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}
	width = 0;
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		current_width = ft_wordcount(line, ' ');
		if (current_width > width)
			width = current_width;
		height++;
		free(line);
	}
	ptr->width = width;
	ptr->height = height;
	close(fd);
}

void	init_fdf(char *path, t_fdf *ptr)
{
	set_sizes(path, ptr);
	ptr->map = (t_map *)malloc(sizeof(t_map) * ptr->width * ptr->height);
	if (!ptr->map)
	{
		perror("Error allocating memory");
		exit(1);
	}
	read_fdf(path, ptr);
}
