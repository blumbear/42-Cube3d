/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:59 by tom               #+#    #+#             */
/*   Updated: 2025/06/04 20:38:10 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	dof_loop(int dof, t_coord *ray_coords, t_env *env)
{
	while (dof < DEPTH_OF_FIELD)
	{
		ray_coords->map_x = (int) ray_coords->pos_x >> 6;
		ray_coords->map_y = (int) ray_coords->pos_y >> 6;
		if ((ray_coords->map_x < env->map_width && ray_coords->map_x >= 0)
			&& (ray_coords->map_y < env->map_height && ray_coords->map_y >= 0))
		{
			if (env->map[ray_coords->map_x][ray_coords->map_y] == '1')
				dof = DEPTH_OF_FIELD;
			else
			{
				ray_coords->pos_x += ray_coords->x_offset;
				ray_coords->pos_y += ray_coords->y_offset;
				dof++;
			}
		}
		if (ray_coords->pos_x < 0 || ray_coords->pos_x >= env->map_width * 64
			|| ray_coords->pos_y < 0 || ray_coords->pos_y >= env->map_height
			* 64)
			dof = DEPTH_OF_FIELD;

	}
}

void	infinite_line(t_env *env, t_coord *ray_coords, int *dof)
{
	ray_coords->pos_x = env->player_coord->pos_x;
	ray_coords->pos_y = env->player_coord->pos_y;
	*dof = DEPTH_OF_FIELD;
}

void	vertical_checks(t_env *env, t_coord *ray_coords, t_coord *dist)
{
	int		dof;

	dof = 0;
	if (ray_coords->angle > PI)
		raycasting_south(env, ray_coords);
	else if (ray_coords->angle < PI)
		raycasting_north(env, ray_coords);
	else
		infinite_line(env, ray_coords, &dof);
	dof_loop(dof, ray_coords, env);
	dist->pos_x = env->player_coord->pos_x;
	dist->pos_y = env->player_coord->pos_y;
	dist->temp = calculate_dist(*(env)->player_coord, *dist);
}

void	horizontal_checks(t_env *env, t_coord *ray_coords, t_coord *dist)
{
	int		dof;

	dof = 0;
	if (ray_coords->angle > PI / 2 && ray_coords->angle < (3 * PI) / 2)
		raycasting_west(env, ray_coords);
	else if (ray_coords->angle > (3 * PI) / 2 || ray_coords->angle < PI / 2)
		raycasting_east(env, ray_coords);
	else
		infinite_line(env, ray_coords, &dof);
	dof_loop(dof, ray_coords, env);
	dist->pos_x = env->player_coord->pos_x;
	dist->pos_y = env->player_coord->pos_y;
	dist->temp = calculate_dist(*(env)->player_coord, *dist);
}

void	draw_rays(t_env *env)
{
	int			i;
	t_coord		ray_coords;
	t_coord		dist_h;
	t_coord		dist_v;
	float		final_dist;

	i = 0;
	ray_coords.pos_x = env->player_coord->pos_x;
	ray_coords.pos_y = env->player_coord->pos_y;
	ray_coords.angle = env->player_coord->angle - DEG_TO_RAD;
	if (ray_coords.angle < 0)
		ray_coords.angle += 2 * PI;
	if (ray_coords.angle > 2 * PI)
		ray_coords.angle -= 2 * PI;
	ray_coords.map_x = 0;
	ray_coords.map_y = 0;
	ray_coords.x_offset = 0;
	ray_coords.y_offset = 0;
	dist_v.pos_x = 0;
	dist_v.pos_y = 0;
	dist_v.temp = 1000000;
	dist_h.pos_x = 0;
	dist_h.pos_y = 0;
	dist_h.temp = 1000000;
	final_dist = 0;
	while (i < 60)
	{
		vertical_checks(env, &ray_coords, &dist_v);
		horizontal_checks(env, &ray_coords,&dist_h);
		// printf("ray x = %f\n ray y = %f\n ray angle %f\n", ray_coords.pos_x, ray_coords.pos_y, ray_coords.angle);
		if (dist_h.temp < dist_v.temp)
		{
			ray_coords.pos_x = dist_h.pos_x;
			ray_coords.pos_y = dist_h.pos_y;
			final_dist = dist_h.temp;
		}
		else
		{
			ray_coords.pos_x = dist_v.pos_x;
			ray_coords.pos_y = dist_v.pos_y;
			final_dist = dist_v.temp;
		}
		ray_coords.angle += DEG_TO_RAD;
		if (ray_coords.angle < 0)
			ray_coords.angle += 2 * PI;
		if (ray_coords.angle > 2 * PI)
			ray_coords.angle -= 2 * PI;
		draw_3d(env, ray_coords, final_dist, i);
		i++;
	}
}

void	calculate_ray_direction(t_env *env, int x, t_ray ray_coords)
{
	ray_coords.camera_x = 2 * x / (double)WIDTH - 1;
	ray_coords.dir_x = env->player_coord.dir_x + env->player_coord.plane_x
		* ray_coords.camera_x;
	ray_coords.dir_y = env->player_coord.dir_y + env->player_coord.plane_y
		* ray_coords.camera_x;
	ray_coords.map_x = (int)env->player_coord.pos_x;
	ray_coords.map_y = (int)env->player_coord.pos_y;
	ray_coords.deltadist_x = fabs(1 / ray_coords.dir_x);
	ray_coords.deltadist_y = fabs(1 / ray_coords.dir_y);
}

void	init_dda(t_game *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.sidedist_x = (game->player.pos_x - game->ray.map_x)
			* game->ray.deltadist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.sidedist_x = (game->ray.map_x + 1.0 - game->player.pos_x)
			* game->ray.deltadist_x;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.sidedist_y = (game->player.pos_y - game->ray.map_y)
			* game->ray.deltadist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.sidedist_y = (game->ray.map_y + 1.0 - game->player.pos_y)
			* game->ray.deltadist_y;
	}
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray.sidedist_x < game->ray.sidedist_y)
		{
			game->ray.sidedist_x += game->ray.deltadist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedist_y += game->ray.deltadist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->map[game->ray.map_y][game->ray.map_x] == '1'
			|| game->map[game->ray.map_y][game->ray.map_x] == '2')
			hit = 1;
		if (game->map[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.wall_door = 0;
		if (game->map[game->ray.map_y][game->ray.map_x] == '2')
			game->ray.wall_door = 1;
	}
}

void	calculate_wall_distance(t_game *game, int *line_height, int *tex_x)
{
	double	wall_x;

	if (game->ray.side == 0)
		game->ray.wall_dist = (game->ray.map_x - game->player.pos_x + (1
					- game->ray.step_x) / 2) / game->ray.dir_x;
	else
		game->ray.wall_dist = (game->ray.map_y - game->player.pos_y + (1
					- game->ray.step_y) / 2) / game->ray.dir_y;
	if (game->ray.side == 0)
		wall_x = game->player.pos_y + game->ray.wall_dist * game->ray.dir_y;
	else
		wall_x = game->player.pos_x + game->ray.wall_dist * game->ray.dir_x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)T_WIDTH);
	if (game->ray.side == 0 && game->ray.dir_x > 0)
		*tex_x = T_WIDTH - *tex_x - 1;
	if (game->ray.side == 1 && game->ray.dir_y < 0)
		*tex_x = T_WIDTH - *tex_x - 1;
	*line_height = (int)(HEIGHT / game->ray.wall_dist);
}