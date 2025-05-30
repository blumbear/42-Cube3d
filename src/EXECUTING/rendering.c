/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:28:06 by tom               #+#    #+#             */
/*   Updated: 2025/05/29 23:37:08 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	render_frame(t_env *env)
{
	static int	i = 0;

	draw_background(env);
	draw_rays(env);
	if (i == 0)
		mlx_image_to_window(env->mlx, env->window, 0, 0);
	i++;
}

void	draw_background(t_env *env)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(env->window, x, y, CEILING_COLOR);
		y++;
	}
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(env->window, x, y, FLOOR_COLOR);
		y++;
	}
}

void	draw_3d(t_env *env, t_coord ray_coords, float final_dist, int i)
{
	float	line_height;
	int		begin_line;
	int		end_line;
	int		x;
	int		y;
	(void)ray_coords;

	y = 0;
	x = (i * 8) + WIDTH;
	line_height = (CUBE_SIZE * HEIGHT) / final_dist;
	if (line_height > HEIGHT)
		line_height = HEIGHT;
	begin_line = -line_height / 2 + HEIGHT / 2;
	if (begin_line < 0)
		begin_line = 0;
	end_line = line_height / 2 + HEIGHT / 2;
	if (end_line >= HEIGHT)
		end_line = HEIGHT - 1;
	while (y < end_line)
	{
		mlx_put_pixel(env->window, x, y, 0x000000FF);
		y++;
	}
}
