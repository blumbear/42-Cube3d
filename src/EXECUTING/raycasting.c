/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:59 by tom               #+#    #+#             */
/*   Updated: 2025/06/05 12:07:17 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

// void	dof_loop(int dof, t_ray *ray_coords, t_env *env)
// {
// 	while (dof < DEPTH_OF_FIELD)
// 	{
// 		ray_coords->map_x = (int) ray_coords->dir_x >> 6;
// 		ray_coords->map_y = (int) ray_coords->dir_y >> 6;
// 		if ((ray_coords->map_x < env->map_width && ray_coords->map_x >= 0)
// 			&& (ray_coords->map_y < env->map_height && ray_coords->map_y >= 0))
// 		{
// 			if (env->map[ray_coords->map_x][ray_coords->map_y] == '1')
// 				dof = DEPTH_OF_FIELD;
// 			else
// 			{
// 				ray_coords->dir_x += ray_coords->x_offset;
// 				ray_coords->dir_y += ray_coords->y_offset;
// 				dof++;
// 			}
// 		}
// 		if (ray_coords->dir_x < 0 || ray_coords->dir_x >= env->map_width * 64
// 			|| ray_coords->dir_y < 0 || ray_coords->dir_y >= env->map_height
// 			* 64)
// 			dof = DEPTH_OF_FIELD;

// 	}
// }

// void	infinite_line(t_env *env, t_ray *ray_coords, int *dof)
// {
// 	ray_coords->dir_x = env->player_coord->pos_x;
// 	ray_coords->dir_y = env->player_coord->pos_y;
// 	*dof = DEPTH_OF_FIELD;
// }

// void	vertical_checks(t_env *env, t_ray *ray_coords, t_coord *dist)
// {
// 	int		dof;

// 	dof = 0;
// 	if (ray_coords->angle > PI)
// 		raycasting_south(env, ray_coords);
// 	else if (ray_coords->angle < PI)
// 		raycasting_north(env, ray_coords);
// 	else
// 		infinite_line(env, ray_coords, &dof);
// 	dof_loop(dof, ray_coords, env);
// 	dist->pos_x = env->player_coord->pos_x;
// 	dist->pos_y = env->player_coord->pos_y;
// 	dist->temp = calculate_dist(*(env)->player_coord, *dist);
// }

// void	horizontal_checks(t_env *env, t_ray *ray_coords, t_coord *dist)
// {
// 	int		dof;

// 	dof = 0;
// 	if (ray_coords->angle > PI / 2 && ray_coords->angle < (3 * PI) / 2)
// 		raycasting_west(env, ray_coords);
// 	else if (ray_coords->angle > (3 * PI) / 2 || ray_coords->angle < PI / 2)
// 		raycasting_east(env, ray_coords);
// 	else
// 		infinite_line(env, ray_coords, &dof);
// 	dof_loop(dof, ray_coords, env);
// 	dist->pos_x = env->player_coord->pos_x;
// 	dist->pos_y = env->player_coord->pos_y;
// 	dist->temp = calculate_dist(*(env)->player_coord, *dist);
// }

// void	draw_rays(t_env *env)
// {
// 	int			i;
// 	t_coord		ray_coords;
// 	t_coord		dist_h;
// 	t_coord		dist_v;
// 	float		final_dist;

// 	i = 0;
// 	ray_coords.pos_x = env->player_coord->pos_x;
// 	ray_coords.pos_y = env->player_coord->pos_y;
// 	ray_coords.angle = env->player_coord->angle - DEG_TO_RAD;
// 	if (ray_coords.angle < 0)
// 		ray_coords.angle += 2 * PI;
// 	if (ray_coords.angle > 2 * PI)
// 		ray_coords.angle -= 2 * PI;
// 	ray_coords.map_x = 0;
// 	ray_coords.map_y = 0;
// 	ray_coords.x_offset = 0;
// 	ray_coords.y_offset = 0;
// 	dist_v.pos_x = 0;
// 	dist_v.pos_y = 0;
// 	dist_v.temp = 1000000;
// 	dist_h.pos_x = 0;
// 	dist_h.pos_y = 0;
// 	dist_h.temp = 1000000;
// 	final_dist = 0;
// 	while (i < 60)
// 	{
// 		vertical_checks(env, &ray_coords, &dist_v);
// 		horizontal_checks(env, &ray_coords,&dist_h);
// 		// printf("ray x = %f\n ray y = %f\n ray angle %f\n", ray_coords.pos_x, ray_coords.pos_y, ray_coords.angle);
// 		if (dist_h.temp < dist_v.temp)
// 		{
// 			ray_coords.pos_x = dist_h.pos_x;
// 			ray_coords.pos_y = dist_h.pos_y;
// 			final_dist = dist_h.temp;
// 		}
// 		else
// 		{
// 			ray_coords.pos_x = dist_v.pos_x;
// 			ray_coords.pos_y = dist_v.pos_y;
// 			final_dist = dist_v.temp;
// 		}
// 		ray_coords.angle += DEG_TO_RAD;
// 		if (ray_coords.angle < 0)
// 			ray_coords.angle += 2 * PI;
// 		if (ray_coords.angle > 2 * PI)
// 			ray_coords.angle -= 2 * PI;
// 		draw_3d(env, ray_coords, final_dist, i);
// 		i++;
// 	}
// }

void	calculate_ray_direction(t_env *env, int x)
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

void	init_dda(t_env *env)
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

void	perform_dda(t_env *env)
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
		env->ray_coords.wall_dist = (env->ray_coords.map_x - env->player_coord->pos_x
				+ (1 - env->ray_coords.step_x) / 2) / env->ray_coords.dir_x;
	else
		env->ray_coords.wall_dist = (env->ray_coords.map_y - env->player_coord->pos_y
				+ (1 - env->ray_coords.step_y) / 2) / env->ray_coords.dir_y;
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

t_limits	calculate_limits(int wall_height)
{
	t_limits	limits;

	limits.beginning = -wall_height / 2 + HEIGHT / 2;
	if (limits.beginning < 0)
		limits.beginning = 0;
	limits.end = wall_height / 2 + HEIGHT / 2;
	if (limits.end >= HEIGHT)
		limits.end = HEIGHT - 1;
	return (limits);
}
