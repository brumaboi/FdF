/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:20:33 by sbruma            #+#    #+#             */
/*   Updated: 2024/09/10 22:03:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*ptr;

	ptr = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(ptr->mlx);
	else if (keydata.key == MLX_KEY_I)
        ptr->scale *= 1.1;
    else if (keydata.key == MLX_KEY_O)
        ptr->scale *= 0.9;
    fill_image(ptr->canvas, 0x000000FF);
	draw_map(ptr);
}

void	fill_image(mlx_image_t *image, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;
	
	if (image->width > 0 && image->height > 0)
	{
		x = 0;
		y = 0;
		while (y < image->height)
		{
			mlx_put_pixel(image, x, y, color);
			x++;
			if (x == image->width)
			{
				y++;
				x = 0;
			}
		}
	}
}

void	error(char *message)
{
	ft_putstr(message);
	exit(1);
}
