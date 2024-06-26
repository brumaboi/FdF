/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:09:06 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/26 12:25:34 by sbruma           ###   ########.fr       */
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

static int	in_bounds(int x, int y)
{
	return (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT);
}

void place_line(mlx_image_t *img, t_pos start, t_pos end, uint32_t color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;

	dx = abs(end.x - start.x);
	dy = abs(end.y - start.y);
	err = dx - dy;
	if (start.x < end.x)
		sx = 1;
	else
		sx = -1;

	if (start.y < end.y)
		sy = 1;
	else
		sy = -1;

	while (1)
	{
		if (in_bounds(start.x, start.y))
			mlx_put_pixel(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		if ((err * 2) > -dy)
		{
			err -= dy;
			start.x += sx;
		}
		if ((err * 2) < dx)
		{
			err += dx;
			start.y += sy;
		}
	}
}

void	draw_line(t_fdf *ptr, int *coords1, int *coords2,
		uint32_t color1, uint32_t color2)
{
	uint32_t	color;
	t_pos		start;
	t_pos		end;

	start.x = coords1[0];
	start.y = coords1[1];
	end.x = coords2[0];
	end.y = coords2[1];
	isometric_projection(&start.x, &start.y, coords1[2], ptr->scale);
	isometric_projection(&end.x, &end.y, coords2[2], ptr->scale);
	start.x += WINDOW_WIDTH / 2;
	start.y += WINDOW_HEIGHT / 2;
	end.x += WINDOW_WIDTH / 2;
	end.y += WINDOW_HEIGHT / 2;
	color = (color1 + color2) / 2;
	place_line(ptr->canvas, start, end, color);
}

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

