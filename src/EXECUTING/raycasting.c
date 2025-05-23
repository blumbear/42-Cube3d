#include "Cube3d.h"

void	draw_rays(t_env *env)
{
	int		i;
	int		dof;
	int		map_x;
	int		map_y;
	t_coord	ray_coords;
	float	x_offset;
	float	y_offset;
	float	tan_inverse;
	float	tan_negative;

	i = 0;
	ray_coords.pos_x = env->player_coord->pos_x;
	ray_coords.pos_y = env->player_coord->pos_y;
	ray_coords.angle = env->player_coord->angle;
	while (i < 1)
	{
		//horizontal
		dof = 0;
		tan_inverse = -1/tan(ray_coords.angle);
		if (ray_coords.angle > PI) //south
		{
			ray_coords.pos_y = (((int)ray_coords.pos_y >> 6) << 6 ) - 0.0001;
			ray_coords.pos_x = (env->player_coord->pos_x - ray_coords.pos_x) * tan_inverse + env->player_coord->pos_x;
			y_offset = -64;
			x_offset = -y_offset * tan_inverse;
		}
		else if (ray_coords.angle < PI) //north
		{
			ray_coords.pos_y = (((int)ray_coords.pos_y >> 6) << 6) + 64;
			ray_coords.pos_x = (env->player_coord->pos_x - ray_coords.pos_x) * tan_inverse + env->player_coord->pos_x;
			y_offset = 64;
			x_offset = -y_offset * tan_inverse;
		}
		else if (ray_coords.angle == 0 || ray_coords.angle == PI) //east or west
		{
			ray_coords.pos_x = env->player_coord->pos_x;
			ray_coords.pos_y = env->player_coord->pos_y;
			dof = DEPTH_OF_FIELD;
		}
		while (dof < DEPTH_OF_FIELD)
		{
			map_x = (int) ray_coords.pos_x >> 6;
			map_y = (int) ray_coords.pos_y >> 6;
			if (map_x >= 0 && map_y >= 0 && map_x < env->map_width && map_y < env->map_height)
			{
				if (env->map[map_x][map_y] == '1')
					dof = DEPTH_OF_FIELD;
				else
				{
					ray_coords.pos_x += x_offset;
					ray_coords.pos_y += y_offset;
					dof++;
				}
			}
		}
		//vertical
		dof = 0;
		tan_negative = -tan(ray_coords.angle);
		if (ray_coords.angle > PI / 2 && ray_coords.angle < (3 * PI) / 2) //West
		{
			ray_coords.pos_x = (((int)ray_coords.pos_y >> 6) << 6 ) - 0.0001;
			ray_coords.pos_y = (env->player_coord->pos_y - ray_coords.pos_y) * tan_negative + env->player_coord->pos_y;
			x_offset = -64;
			y_offset = -x_offset * tan_negative;
		}
		else if (ray_coords.angle < PI / 2 || ray_coords.angle > (3 * PI) / 2) //East
		{
			ray_coords.pos_x = (((int)ray_coords.pos_x >> 6) << 6) + 64;
			ray_coords.pos_y = (env->player_coord->pos_y - ray_coords.pos_y) * tan_negative + env->player_coord->pos_y;
			x_offset = 64;
			y_offset = -x_offset * tan_negative;
		}
		else if (ray_coords.angle == 0 || ray_coords.angle == PI) //North or South
		{
			ray_coords.pos_x = env->player_coord->pos_x;
			ray_coords.pos_y = env->player_coord->pos_y;
			dof = DEPTH_OF_FIELD;
		}
		while (dof < DEPTH_OF_FIELD)
		{
			map_x = (int) ray_coords.pos_x >> 6;
			map_y = (int) ray_coords.pos_y >> 6;
			if (map_x >= 0 && map_y >= 0 && map_x < env->map_width && map_y < env->map_height)
			{
				if (env->map[map_x][map_y] == '1')
					dof = DEPTH_OF_FIELD;
				else
				{
					ray_coords.pos_x += x_offset;
					ray_coords.pos_y += y_offset;
					dof++;
				}
			}
		}
		i++;
	}
}
