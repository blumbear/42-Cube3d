#include "Cube3d.h"

void	render_frame(t_env *env)
{
	static int	i = 0;

	draw_background(env);
	if (i == 0)
		mlx_image_to_window(env->mlx, env->window, 0, 0);
	i++;
}

void	draw_background(t_env *env)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(env->window, x, y, CEILING_COLOR);
		y++;
	}
	while (y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(env->window, x, y, FLOOR_COLOR);
		y++;
	}
}
