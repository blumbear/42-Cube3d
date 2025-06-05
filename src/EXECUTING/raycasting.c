/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:59 by tom               #+#    #+#             */
/*   Updated: 2025/06/05 16:17:08 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	set_ray_dir(t_env *env, int x)
{
	env->ray_coords.camera_x = 2 * x / (double)WIDTH - 1;
	env->ray_coords.dir_x = env->player_coord->dir_x
		+ env->player_coord->plane_x * env->ray_coords.camera_x;
	env->ray_coords.dir_y = env->player_coord->dir_y
		+ env->player_coord->plane_y * env->ray_coords.camera_x;
	env->ray_coords.map_x = (int)env->player_coord->pos_x;
	env->ray_coords.map_y = (int)env->player_coord->pos_y;
	env->ray_coords.delta_x = fabs(1 / env->ray_coords.dir_x);
	env->ray_coords.delta_y = fabs(1 / env->ray_coords.dir_y);
}

void	raycast_start(t_env *env)
{
	if (env->ray_coords.dir_x < 0)
	{
		env->ray_coords.step_x = -1;
		env->ray_coords.side_dist_x = (env->player_coord->pos_x
				- env->ray_coords.map_x) * env->ray_coords.delta_x;
	}
	else
	{
		env->ray_coords.step_x = 1;
		env->ray_coords.side_dist_x = (env->ray_coords.map_x + 1.0
				- env->player_coord->pos_x) * env->ray_coords.delta_x;
	}
	if (env->ray_coords.dir_y < 0)
	{
		env->ray_coords.step_y = -1;
		env->ray_coords.side_dist_y = (env->player_coord->pos_y
				- env->ray_coords.map_y) * env->ray_coords.delta_y;
	}
	else
	{
		env->ray_coords.step_y = 1;
		env->ray_coords.side_dist_y = (env->ray_coords.map_y + 1.0
				- env->player_coord->pos_y) * env->ray_coords.delta_y;
	}
}

void	raycast_loop(t_env *env)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (env->ray_coords.side_dist_x < env->ray_coords.side_dist_y)
		{
			env->ray_coords.side_dist_x += env->ray_coords.delta_x;
			env->ray_coords.map_x += env->ray_coords.step_x;
			env->ray_coords.side = 0;
		}
		else
		{
			env->ray_coords.side_dist_y += env->ray_coords.delta_y;
			env->ray_coords.map_y += env->ray_coords.step_y;
			env->ray_coords.side = 1;
		}
		if (env->map[env->ray_coords.map_y][env->ray_coords.map_x] == '1')
			hit = 1;
	}
}

void	calculate_wall_distance(t_env *env, int *wall_height, int *texture_x)
{
	double	wall_x;

	if (env->ray_coords.side == 0)
		env->ray_coords.wall_dist = (env->ray_coords.map_x
				- env->player_coord->pos_x + (1 - env->ray_coords.step_x) / 2)
			/ env->ray_coords.dir_x;
	else
		env->ray_coords.wall_dist = (env->ray_coords.map_y
				- env->player_coord->pos_y + (1 - env->ray_coords.step_y)
				/ 2) / env->ray_coords.dir_y;
	if (env->ray_coords.side == 0)
		wall_x = env->player_coord->pos_y + env->ray_coords.wall_dist
			* env->ray_coords.dir_y;
	else
		wall_x = env->player_coord->pos_x + env->ray_coords.wall_dist
			* env->ray_coords.dir_x;
	wall_x -= floor(wall_x);
	*texture_x = (int)(wall_x * (double)TEXTURE_DIMENSIONS);
	if (env->ray_coords.side == 0 && env->ray_coords.dir_x > 0)
		*texture_x = TEXTURE_DIMENSIONS - *texture_x - 1;
	if (env->ray_coords.side == 1 && env->ray_coords.dir_y < 0)
		*texture_x = TEXTURE_DIMENSIONS - *texture_x - 1;
	*wall_height = (int)(HEIGHT / env->ray_coords.wall_dist);
}

void	draw_wall_line(t_env *env, int x, int wall_height, int texture_x)
{
	t_limits	limits;
	int			y;
	// int			dist;
	// int			texture_y;
	// mlx_texture_t	*texture;
	(void)texture_x;

	limits = calculate_limits(wall_height);
	// texture = select_texture(env);
	y = limits.beginning;
	while (y < limits.end)
	{
		// dist = y * 256 - HEIGHT * 128 + wall_height * 128;
		// texture_y = ((dist * TEXTURE_DIMENSIONS) / wall_height) / 256;
		mlx_put_pixel(env->window, x, y, 0xFFFFFFFF);
		y++;
	}
}
