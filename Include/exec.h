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

/**
 * @brief The exec_init function simply initializes essential variables and
 * kickstarts the mlx42
 * 
 * @param env A pointer to the main env struct
 */
void	exec_init(t_env *env);
/**
 * @brief This function initializes the player's coordinates according to its
 * placement on the map.
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 * @param dir The direction the player is facing when the game launches
 */
void	init_player_coords(t_coord *coords, int i, int j, char dir);

/*			Rendering			*/
/**
 * @brief The render_frame function calls upon many other rendering fuctions
 * and puts everything together to have a nice lttle image on your screen
 * 
 * @param env A pointer to the main env struct
 */
void	render_frame(t_env *env);
/**
 * @brief The draw_background function is used to draw the "background" (floor 
 * and ceiling) of the frame
 * 
 * @param env A pointer to the main env struct
 */
void	draw_background(t_env *env);
/**
 * @brief The raycasting_south and north functions are used to check if a wall
 * above or below the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_south(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
/**
 * @brief The raycasting_south and north functions are used to check if a wall
 * above or below the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_north(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
/**
 * @brief The raycasting_east and west functions are used to check if a wall
 * to the left or right of the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_east(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
/**
 * @brief The raycasting_east and west functions are used to check if a wall
 * to the left or right of the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_west(t_env *env, t_coord *ray_coords, t_map_co *map_coords);
/**
 * @brief This simple function uses the Pythagoras' theorem to calculate the
 * distance between the player and the wall hitpoint
 * 
 * @param coords_a 
 * @param coords_b 
 * @return float The calculated distance
 */
float	calculate_dist(t_coord coords_a, t_coord coords_b);

void	draw_rays(t_env *env);
void	draw_3d(t_env *env, t_coord ray_coords, float final_dist, int i);

/*			Looping			*/
void	main_loop(void	*param);

/*			Utils			*/
void	print_player_coords(t_coord *coords);
int		get_largest_map_column(t_env *env);

#endif