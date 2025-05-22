#include "Cube3d.h"

void	print_player_coords(t_coord *coords)
{
	printf("player x = %f\n", coords->pos_x);
	printf("player y = %f\n", coords->pos_y);
	printf("delta x = %f\n", coords->delta_x);
	printf("delta y = %f\n", coords->delta_y);
	printf("player angle = %f\n", coords->angle);
}

int	get_largest_map_line(t_env *env)
{
	int	max;
	int	i;

	max = 0;
	i = -1;
	while (env->map_size[++i])
		if (env->map_size[i] > max)
			max = env->map_size[i];
	return (max);
}

int	get_largest_map_column(t_env *env)
{
	int	i;

	i = 0;
	while (env->map_size[i])
		i++;
	return (i);
}
