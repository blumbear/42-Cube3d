/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:59 by tom               #+#    #+#             */
/*   Updated: 2025/05/29 23:27:59 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	dof_loop(int dof, t_coord *ray_coords, t_map_co *map_coords, t_env *env)
{
	while (dof < DEPTH_OF_FIELD)
	{
		map_coords->pos_x = (int) ray_coords->pos_x >> 6;
		map_coords->pos_y = (int) ray_coords->pos_y >> 6;
		if ((map_coords->pos_x < env->map_width && map_coords->pos_x >= 0)
			&& (map_coords->pos_y < env->map_height && map_coords->pos_y >= 0))
		{
			if (env->map[map_coords->pos_x][map_coords->pos_y] == '1')
				dof = DEPTH_OF_FIELD;
			else
			{
				ray_coords->pos_x += map_coords->x_offset;
				ray_coords->pos_y += map_coords->y_offset;
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

void	vertical_checks(t_env *env, t_coord *ray_coords, t_map_co *map_coords,
	t_coord *dist)
{
	int		dof;

	dof = 0;
	if (ray_coords->angle > PI)
		raycasting_south(env, ray_coords, map_coords);
	else if (ray_coords->angle < PI)
		raycasting_north(env, ray_coords, map_coords);
	else
		infinite_line(env, ray_coords, &dof);
	dof_loop(dof, ray_coords, map_coords, env);
	dist->pos_x = env->player_coord->pos_x;
	dist->pos_y = env->player_coord->pos_y;
	dist->temp = calculate_dist(*(env)->player_coord, *dist);
}

void	horizontal_checks(t_env *env, t_coord *ray_coords, t_map_co *map_coords,
	t_coord *dist)
{
	int		dof;

	dof = 0;
	if (ray_coords->angle > PI / 2 && ray_coords->angle < (3 * PI) / 2)
		raycasting_west(env, ray_coords, map_coords);
	else if (ray_coords->angle > (3 * PI) / 2 || ray_coords->angle < PI / 2)
		raycasting_east(env, ray_coords, map_coords);
	else
		infinite_line(env, ray_coords, &dof);
	dof_loop(dof, ray_coords, map_coords, env);
	dist->pos_x = env->player_coord->pos_x;
	dist->pos_y = env->player_coord->pos_y;
	dist->temp = calculate_dist(*(env)->player_coord, *dist);
}

void	draw_rays(t_env *env)
{
	int			i;
	t_coord		ray_coords;
	t_map_co	map_coords;
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
	map_coords.pos_x = 0;
	map_coords.pos_y = 0;
	map_coords.x_offset = 0;
	map_coords.y_offset = 0;
	dist_v.pos_x = 0;
	dist_v.pos_y = 0;
	dist_v.temp = 1000000;
	dist_h.pos_x = 0;
	dist_h.pos_y = 0;
	dist_h.temp = 1000000;
	final_dist = 0;
	while (i < 60)
	{
		vertical_checks(env, &ray_coords, &map_coords, &dist_v);
		horizontal_checks(env, &ray_coords, &map_coords, &dist_h);
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
