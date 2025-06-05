/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:38 by tom               #+#    #+#             */
/*   Updated: 2025/06/05 12:23:17 by bchedru          ###   ########.fr       */
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

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*env;

	(void)keydata;
	env = (t_env *)param;
	if (mlx_is_key_down(env->mlx, MLX_KEY_W))
		move_forward(env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_S))
		move_backward(env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_A))
		move_left(env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_D))
		move_right(env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		rotate_camera(env, -ROTATION_SPEED);
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		rotate_camera(env, ROTATION_SPEED);
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		clean_exit(env);
}

void	main_loop(void	*param)
{
	t_env							*env;
	static unsigned long long int	last_rendering = 0;
	unsigned long long int			current_time;

	env = (t_env *)param;
	mlx_key_hook(env->mlx, &keyhook, env);
	current_time = mlx_get_time() * 1000;
	if (current_time - last_rendering >= 1000 / FPS)
	{
		// printf("player x = %f\n player y = %f\n", env->player_coord->pos_x, env->player_coord->pos_y);
		render_frame(env);
		last_rendering = current_time;
	}
}
