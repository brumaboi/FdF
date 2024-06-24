/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:20:45 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 17:14:22 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_mlx(t_fdf *ptr)
{
	int32_t	width;
	int32_t	height;

	ptr->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "FdF", 0);
	if (!ptr->mlx)
	{
		ft_putstr("mlx_init failed\n");
		exit(1);
	}
	ptr->win = mlx_new_image(ptr->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!ptr->win || mlx_image_to_window(ptr->mlx, ptr->win, 0, 0) < 0)
	{
		ft_putstr("mlx_new_image failed\n");
		exit(1);
	}
	mlx_get_monitor_size(0, &width, &height);
	if (width < WINDOW_WIDTH || height < WINDOW_HEIGHT)
	{
		mlx_terminate(ptr->mlx);
		width = fmin(width, height) * 0.7;
		height = width;
		ptr->mlx = mlx_init(width, height, "FdF", 0);
		if (!ptr->mlx)
		{
			ft_putstr("mlx_init failed\n");
			exit(1);
		}
	}
	ptr->canvas = mlx_new_image(ptr->mlx, ptr->mlx->width, ptr->mlx->height);
	if (!ptr->canvas || mlx_image_to_window(ptr->mlx, ptr->canvas, 0, 0) < 0)
		ft_putstr("mlx_new_image failed");
}
