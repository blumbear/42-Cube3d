/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:28:06 by tom               #+#    #+#             */
/*   Updated: 2025/06/11 14:14:56 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	render_frame(t_env *env)
{
	int			x;
	static int	i = 0;

	x = 0;
	draw_background(env);
	while (x < WIDTH)
	{
		render_wall(env, x);
		x++;
	}
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
			mlx_put_pixel(env->window, x, y, env->c_color);
		y++;
	}
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(env->window, x, y, env->f_color);
		y++;
	}
}

void	render_wall(t_env *env, int x)
{
	int	texture_x;
	int	wall_height;

	set_ray_dir(env, x);
	raycast_start(env);
	raycast_loop(env);
	calculate_wall_distance(env, &wall_height, &texture_x);
	draw_wall_line(env, x, wall_height, texture_x);
}
