/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:38 by tom               #+#    #+#             */
/*   Updated: 2025/05/30 02:23:45 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	move_forward(t_env *env)
{
	t_coord	*coord;

	coord = env->player_coord;
	coord->pos_x += coord->delta_x * MOVEMENT_SPEED;
	coord->pos_y += coord->delta_y * MOVEMENT_SPEED;
}

void	move_backward(t_env *env)
{
	t_coord	*coord;

	coord = env->player_coord;
	coord->pos_x -= coord->delta_x;
	coord->pos_y -= coord->delta_y;
}

// void	move_left(t_env *env)
// {
// 	t_coord	*coord;

// 	coord = env->player_coord;
// 	coord->pos_x += coord->delta_x;
// 	coord->pos_y += coord->delta_y;
// }

void	rotate_camera(t_coord *coord, bool right)
{
	if (right)
	{
		coord->angle += ROTATION_SPEED;
		if (coord->angle > 2 * PI)
			coord->angle -= 2 * PI;
		coord->delta_x = cos(coord->angle) * 5;
		coord->delta_y = sin (coord->angle) * 5;
	}
	else
	{
		coord->angle -= ROTATION_SPEED;
		if (coord->angle < 0)
			coord->angle += 2 * PI;
		coord->delta_x = cos(coord->angle) * 5;
		coord->delta_y = sin (coord->angle) * 5;
	}
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
	// if (mlx_is_key_down(env->mlx, MLX_KEY_A))
	// 	move_left(env);
	// if (mlx_is_key_down(env->mlx, MLX_KEY_D))
	// 	move_right(env);
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		rotate_camera(env->player_coord, 0);
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		rotate_camera(env->player_coord, 1);
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
		// printf("player x = %f\n player y = %f\n delta x = %f\n delta y = %f\n player angle = %f\n", env->player_coord->pos_x, env->player_coord->pos_y, env->player_coord->delta_x, env->player_coord->delta_y, env->player_coord->angle);
		render_frame(env);
		last_rendering = current_time;
	}
}
