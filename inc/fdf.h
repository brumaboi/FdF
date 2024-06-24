/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruma <sbruma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:23:10 by sbruma            #+#    #+#             */
/*   Updated: 2024/06/24 17:10:24 by sbruma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024
# define ISO_ANGLE 0.523599

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map_xyz
{
	int	x;
	int	y;
	int	z;
	int	max_z;
	int	min_z;
}	t_map;

typedef struct s_point_xy
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_point;

typedef struct s_fdf
{
	mlx_t		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	float		scale;
	mlx_image_t	*canvas;
	t_pos		center;
	t_map		*map;
	t_point		*point;
}	t_fdf;

//fdf_utils.c
void	key_hook(mlx_key_data_t keydata, void *param);
void	fill_image(mlx_image_t *image, uint32_t color);

//init_mlx.c
void	init_mlx(t_fdf *ptr);

//window_setup.c
void	window_setup(char **argv, t_fdf *ptr);

//init_fdf.c
void	init_fdf(char *path, t_fdf *ptr);

#endif