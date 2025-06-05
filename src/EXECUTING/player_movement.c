/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:27:33 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/05 16:31:30 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	move_forward(t_env *env)
{
	if (env->map[(int)(env->player_coord->pos_y)][(int)(env->player_coord->pos_x
			+ env->player_coord->dir_x * (MOVEMENT_SPEED + 0.1))] != '1')
		env->player_coord->pos_x += env->player_coord->dir_x * MOVEMENT_SPEED;
	if (env->map[(int)(env->player_coord->pos_y + env->player_coord->dir_y
			* (MOVEMENT_SPEED + 0.1))][(int)(env->player_coord->pos_x)] != '1')
		env->player_coord->pos_y += env->player_coord->dir_y * MOVEMENT_SPEED;
}

void	move_backward(t_env *env)
{
	if (env->map[(int)(env->player_coord->pos_y)][(int)(env->player_coord->pos_x
			- env->player_coord->dir_x * (MOVEMENT_SPEED + 0.1))] != '1')
		env->player_coord->pos_x -= env->player_coord->dir_x * MOVEMENT_SPEED;
	if (env->map[(int)(env->player_coord->pos_y - env->player_coord->dir_y
			* (MOVEMENT_SPEED + 0.1))][(int)(env->player_coord->pos_x)] != '1')
		env->player_coord->pos_y -= env->player_coord->dir_y * MOVEMENT_SPEED;
}

void	move_left(t_env *env)
{
	double	new_x;
	double	new_y;

	new_x = env->player_coord->dir_y;
	new_y = -env->player_coord->dir_x;
	if (env->map[(int)(env->player_coord->pos_y)][(int)(env->player_coord->pos_x
			+ new_x * (MOVEMENT_SPEED + 0.1))] != '1')
		env->player_coord->pos_x += new_x * MOVEMENT_SPEED;
	if (env->map[(int)(env->player_coord->pos_y + new_y
			* (MOVEMENT_SPEED + 0.1))][(int)(env->player_coord->pos_x)] != '1')
		env->player_coord->pos_y += new_y * MOVEMENT_SPEED;
}

void	move_right(t_env *env)
{
	double	new_x;
	double	new_y;

	new_x = -env->player_coord->dir_y;
	new_y = env->player_coord->dir_x;
	if (env->map[(int)(env->player_coord->pos_y)][(int)(env->player_coord->pos_x
			+ new_x * (MOVEMENT_SPEED + 0.1))] != '1')
		env->player_coord->pos_x += new_x * MOVEMENT_SPEED;
	if (env->map[(int)(env->player_coord->pos_y + new_y
			* (MOVEMENT_SPEED + 0.1))][(int)(env->player_coord->pos_x)] != '1')
		env->player_coord->pos_y += new_y * MOVEMENT_SPEED;
}

void	rotate_camera(t_env *env, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = env->player_coord->dir_x;
	env->player_coord->dir_x = env->player_coord->dir_x * cos(angle)
		- env->player_coord->dir_y * sin(angle);
	env->player_coord->dir_y = old_dir_x * sin(angle)
		+ env->player_coord->dir_y * cos(angle);
	old_plane_x = env->player_coord->plane_x;
	env->player_coord->plane_x = env->player_coord->plane_x
		* cos(angle) - env->player_coord->plane_y * sin(angle);
	env->player_coord->plane_y = old_plane_x * sin(angle)
		+ env->player_coord->plane_y * cos(angle);
}
