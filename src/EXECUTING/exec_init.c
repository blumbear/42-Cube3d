<<<<<<< HEAD
#include "Cub3d.h"
=======
#include "Cube3d.h"
>>>>>>> 130d7e4 (Bartime (#7))

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
<<<<<<< HEAD

void	init_player_coords(t_coord *coords, int i, int j, char dir)
{
	if (dir == 'N')
		coords->angle = PI / 2;
	else if (dir == 'E')
		coords->angle = PI * 2;
	else if (dir == 'S')
		coords->angle = (3 * PI) / 2;
	else
		coords->angle = PI;
	coords->pos_x = (double)i;
	coords->pos_y = (double)j;
	coords->delta_x = cos(coords->angle) * 5;
	coords->delta_y = sin (coords->angle) * 5;
}
=======
>>>>>>> 130d7e4 (Bartime (#7))
