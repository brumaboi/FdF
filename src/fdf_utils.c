/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:20:33 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 17:00:58 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*s;

	s = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(s->mlx);
}

void	fill_image(mlx_image_t *image, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

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
