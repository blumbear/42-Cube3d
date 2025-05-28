#include "Cub3d.h"

int	get_largest_map_column(t_env *env)
{
	int	i;

	i = 0;
	while (env->map_size[i])
		i++;
	return (i);
}
