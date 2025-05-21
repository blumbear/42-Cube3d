#include "Cube3d.h"

void	print_player_coords(t_coord *coords)
{
	printf("player x = %f\n", coords->pos_x);
	printf("player y = %f\n", coords->pos_y);
	printf("delta x = %f\n", coords->delta_x);
	printf("delta y = %f\n", coords->delta_y);
	printf("player angle = %f\n", coords->player_angle);
}
