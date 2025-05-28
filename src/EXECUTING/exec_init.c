#include "Cube3d.h"

void	init_window(t_env *env)
{
	env->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", false);
	if (!env->mlx)
		(end_prog(env), exit(0));
	env->window = mlx_new_image(env->mlx, WIDTH, HEIGHT);
}

void	exec_init(t_env *env)
{
	env->map_height = get_largest_map_column(env);
	init_window(env);
	mlx_loop_hook(env->mlx, main_loop, env);
}
