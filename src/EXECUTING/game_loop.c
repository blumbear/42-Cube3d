/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:38 by tom               #+#    #+#             */
/*   Updated: 2025/06/14 10:42:25 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
		if (last_rendering == 0)
			render_frame(env, true);
		else
			render_frame(env, false);
		last_rendering = current_time;
	}
}
