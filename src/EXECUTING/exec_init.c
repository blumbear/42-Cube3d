/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:24:36 by tom               #+#    #+#             */
/*   Updated: 2025/06/05 16:18:54 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	init_window(t_env *env)
{
	env->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!env->mlx)
		(end_prog(env), exit(0));
	env->window = mlx_new_image(env->mlx, WIDTH, HEIGHT);
}

void	init_ray(t_env *env)
{
	env->ray_coords.camera_x = 0.0;
	env->ray_coords.dir_x = env->player_coord->dir_x;
	env->ray_coords.dir_y = env->player_coord->dir_y;
	env->ray_coords.map_x = (int)env->player_coord->pos_x;
	env->ray_coords.map_y = (int)env->player_coord->pos_y;
	env->ray_coords.step_x = 0;
	env->ray_coords.step_y = 0;
	env->ray_coords.side_dist_x = 0.0;
	env->ray_coords.side_dist_y = 0.0;
	env->ray_coords.delta_x = 0.0;
	env->ray_coords.delta_y = 0.0;
	env->ray_coords.wall_dist = 0.0;
	env->ray_coords.side = -1;
}

void	exec_init(t_env *env)
{
	env->map_height = get_largest_map_column(env);
	init_ray(env);
	init_window(env);
	mlx_loop_hook(env->mlx, main_loop, env);
}

void	init_player_coords(t_coord *coords, int i, int j, char dir)
{
	if (dir == 'N')
		player_init_north(coords, i, j);
	else if (dir == 'E')
		player_init_east(coords, i, j);
	else if (dir == 'S')
		player_init_south(coords, i, j);
	else
		player_init_west(coords, i, j);
}
