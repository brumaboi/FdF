/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:09:06 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/25 19:41:14 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric_projection(int *x, int *y, int z, float scale)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(ISO_ANGLE) * scale;
	*y = (prev_x + prev_y) * sin(ISO_ANGLE) * scale - z * scale;
}

void	get_isometric_coordinates(t_fdf *ptr, int x, int y,
		int *coords, uint32_t *color)
{
	t_map	point;

	point = ptr->map[y * ptr->width + x];
	coords[0] = point.x;
	coords[1] = point.y;
	coords[2] = point.z;
	*color = point.color;
}

void draw_line();
//function that draws from point 1 to point 2
//converting the coordinates to isometric

void	draw_x_line(t_fdf *ptr, int x, int y)
{
	int			coords1[3];
	int			coords2[3];
	uint32_t	color1;
	uint32_t	color2;

	get_isometric_coordinates(ptr, x, y, coords1, &color1);
	get_isometric_coordinates(ptr, x + 1, y, coords2, &color2);
	draw_line(ptr, coords1, coords2, color1, color2);
}

void	draw_y_line(t_fdf *ptr, int x, int y)
{
	int			coords1[3];
	int			coords2[3];
	uint32_t	color1;
	uint32_t	color2;

	get_isometric_coordinates(ptr, x, y, coords1, &color1);
	get_isometric_coordinates(ptr, x, y + 1, coords2, &color2);
	draw_line(ptr, coords1, coords2, color1, color2);
}

void	draw_map(t_fdf *ptr)
{
	int	y;
	int	x;

	y = 0;
	while (y < ptr->height)
	{
		x = 0;
		while (x < ptr->width)
		{
			if (x < ptr->width - 1)
				draw_x_line(ptr, x, y);
			if (y < ptr->height - 1)
				draw_y_line(ptr, x, y);
			x++;
		}
		y++;
	}
}

