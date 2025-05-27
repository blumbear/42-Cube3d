#include "Cube3d.h"

void	raycasting_south(t_env *env, t_coord *ray_coords, t_map_co *map_coords)
{
	float	tan_inverse;

	tan_inverse = -1 / tan(ray_coords->angle);
	ray_coords->pos_y = (((int)ray_coords->pos_y >> 6) << 6) - 0.0001;
	ray_coords->pos_x = (env->player_coord->pos_x - ray_coords->pos_x)
		* tan_inverse + env->player_coord->pos_x;
	map_coords->y_offset = -64;
	map_coords->x_offset = -map_coords->y_offset * tan_inverse;
}

void	raycasting_north(t_env *env, t_coord *ray_coords, t_map_co *map_coords)
{
	float	tan_inverse;

	tan_inverse = -1 / tan(ray_coords->angle);
	ray_coords->pos_y = (((int)ray_coords->pos_y >> 6) << 6) + 64;
	ray_coords->pos_x = (env->player_coord->pos_x - ray_coords->pos_x)
		* tan_inverse + env->player_coord->pos_x;
	map_coords->y_offset = 64;
	map_coords->x_offset = -map_coords->y_offset * tan_inverse;
}

void	raycasting_west(t_env *env, t_coord *ray_coords, t_map_co *map_coords)
{
	float	tan_negative;

	tan_negative = -tan(ray_coords->angle);
	ray_coords->pos_x = (((int)ray_coords->pos_x >> 6) << 6) - 0.0001;
	ray_coords->pos_y = (env->player_coord->pos_y - ray_coords->pos_y)
		* tan_negative + env->player_coord->pos_y;
	map_coords->x_offset = -64;
	map_coords->y_offset = -map_coords->x_offset * tan_negative;
}

void	raycasting_east(t_env *env, t_coord *ray_coords, t_map_co *map_coords)
{
	float	tan_negative;

	tan_negative = -tan(ray_coords->angle);
	ray_coords->pos_x = (((int)ray_coords->pos_x >> 6) << 6) + 64;
	ray_coords->pos_y = (env->player_coord->pos_y - ray_coords->pos_y)
		* tan_negative + env->player_coord->pos_y;
	map_coords->x_offset = 64;
	map_coords->y_offset = -map_coords->x_offset * tan_negative;
}

float	calculate_dist(t_coord coords_a, t_coord coords_b)
{
	return (sqrt((coords_b.pos_x * coords_a.pos_x)
			+ (coords_b.pos_y * coords_a.pos_y)));
}
