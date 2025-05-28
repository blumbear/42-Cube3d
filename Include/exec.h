#ifndef EXEC_H
# define EXEC_H

# define PI 3.1415926535
# define HEIGHT 512
# define WIDTH 1024
# define FPS 60
# define CEILING_COLOR 0x0000FFFF
# define FLOOR_COLOR 0x7B7B7BFF
# define ROTATION_SPEED 0.1
# define MOVEMENT_SPEED 0.75
# define DEPTH_OF_FIELD 8
# define DEG_TO_RAD 0.0174533
# define CUBE_SIZE 64


/*			Initialization			*/
void	exec_init(t_env *env);
void	init_player_coords(t_coord *coords, int i, int j, char dir);

/*			Rendering			*/
void	render_frame(t_env *frame);
void	draw_background(t_env *env);
void	raycasting_south(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
void	raycasting_north(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
void	raycasting_east(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
void	raycasting_west(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
float	calculate_dist(t_coord coords_a, t_coord coords_b);
void	draw_rays(t_env *env);
void	draw_3d(t_env *env, t_coord ray_coords, float final_dist, int i);

/*			Looping			*/
void	main_loop(void	*param);

/*			Utils			*/
void	print_player_coords(t_coord *coords);
int		get_largest_map_column(t_env *env);

#endif