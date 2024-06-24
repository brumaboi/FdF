/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:45:25 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 17:08:22 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	center_img(t_fdf *ptr)
{
	t_pos	center;
	size_t	i;

	center.x = ptr->width / 2;
	center.y = ptr->height / 2;
	i = 0;
	while (i < (size_t)(ptr->width * ptr->height))
	{
		ptr->map[i].x -= center.x;
		ptr->map[i].y -= center.y;
		i++;
	}
}

static int	check_format(char *path)
{
	char	*extension;

	extension = ft_strrchr(path, '.');
	if (extension)
	{
		if (!ft_strncmp(extension, ".fdf", 4))
			return (1);
	}
	return (0);
}

void	window_setup(char **argv, t_fdf *ptr)
{
	if (!check_format(argv[1]))
	{
		ft_putstr("Wrong file format! Allowed format: .fdf\n");
		exit(1);
	}
	init_fdf(argv[1], ptr);
	center_img(ptr);
	ptr->scale = ft_ismin(WINDOW_WIDTH / ptr->width,
			WINDOW_HEIGHT / ptr->height) / 2.0;
}
