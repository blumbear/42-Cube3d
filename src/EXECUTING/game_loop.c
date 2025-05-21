#include "Cube3d.h"

void	move_forward(t_env *env)
{
	t_coord	*coord;

	coord = env->player_coord;
	coord->pos_x += coord->delta_x;
	coord->pos_y += coord->delta_y;
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
		coord->player_angle += 0.1;
		if (coord->player_angle < 2 * PI)
			coord->player_angle -= 2 * PI;
		coord->delta_x = cos(coord->player_angle) * 5;
		coord->delta_y = sin (coord->player_angle) * 5;
	}
	else
	{
		coord->player_angle -= 0.1;
		if (coord->player_angle < 0)
			coord->player_angle += 2 * PI;
		coord->delta_x = cos(coord->player_angle) * 5;
		coord->delta_y = sin (coord->player_angle) * 5;
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
		// print_player_coords(env->player_coord);
		render_frame(env);
		last_rendering = current_time;
	}
}
