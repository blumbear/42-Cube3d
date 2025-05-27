#ifndef EXEC_H
# define EXEC_H

# define PI 3.1415926535
# define HEIGHT 512
# define WIDTH 1024
# define FPS 60
# define CEILING_COLOR 0x0000FFFF
# define FLOOR_COLOR 0x7B7B7BFF
# define ROTATION_SPEED 0.1
# define MOVEMENT_SPEED 1
# define DEPTH_OF_FIELD 8

/*			Initialization			*/
void	exec_init(t_env *env);

/*			Rendering			*/
void	render_frame(t_env *frame);
void	draw_background(t_env *env);
void	raycasting_south(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
void	raycasting_north(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
void	raycasting_east(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
void	raycasting_west(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
float	calculate_dist(t_coord coords_a, t_coord coords_b);
void	draw_rays(t_env *env);

/*			Looping			*/
void	main_loop(void	*param);

/*			Utils			*/
void	print_player_coords(t_coord *coords);
int		get_largest_map_line(t_env *env);
int		get_largest_map_column(t_env *env);

#endif