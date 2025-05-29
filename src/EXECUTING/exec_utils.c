<<<<<<< HEAD
#include "Cub3d.h"
=======
#include "Cube3d.h"
>>>>>>> 130d7e4 (Bartime (#7))

int	get_largest_map_column(t_env *env)
{
	int	i;

	i = 0;
	while (env->map_size[i])
		i++;
	return (i);
}
