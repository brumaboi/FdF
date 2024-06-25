/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:20:20 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/25 19:38:31 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	ptr;

	if (argc != 2)
        error("Usage: ./fdf <filename>\n");
	window_setup(argv, &ptr);
	init_mlx(&ptr);
	fill_image(ptr.canvas, 0x000000FF);
    draw_map(&ptr);
	mlx_key_hook(ptr.mlx, key_hook, &ptr);
	mlx_loop(ptr.mlx);
	mlx_terminate(ptr.mlx);
	free(ptr.map);
	return (0);
}
