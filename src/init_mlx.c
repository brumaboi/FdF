/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:20:45 by sbruma            #+#    #+#             */
/*   Updated: 2024/09/10 19:16:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_mlx(t_fdf *ptr)
{
	int32_t	width;
	int32_t	height;

	ptr->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "FdF", 0);
	if (!ptr->mlx)
		error("mlx_init failed\n");
	ptr->win = mlx_new_image(ptr->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!ptr->win || mlx_image_to_window(ptr->mlx, ptr->win, 0, 0) < 0)
		error("mlx_new_image failed\n");
	mlx_get_monitor_size(0, &width, &height);
	if (width < WINDOW_WIDTH || height < WINDOW_HEIGHT)
	{
		mlx_terminate(ptr->mlx);
		width = fmin(width, height) * 0.7;
		height = width;
		ptr->mlx = mlx_init(width, height, "FdF", 0);
		if (!ptr->mlx)
			error("mlx_init failed\n");
	}
	ptr->canvas = mlx_new_image(ptr->mlx, ptr->mlx->width, ptr->mlx->height);
	if (!ptr->canvas || mlx_image_to_window(ptr->mlx, ptr->canvas, 0, 0) < 0)
		error("mlx_init failed\n");
}
