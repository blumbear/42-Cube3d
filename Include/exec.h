/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:09 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/05 16:18:33 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define PI 3.1415926535
# define HEIGHT 512
# define WIDTH 1024
# define FPS 60
# define CEILING_COLOR 0x0000FFFF
# define FLOOR_COLOR 0x7B7B7BFF
# define ROTATION_SPEED 0.1
# define MOVEMENT_SPEED 0.1
# define DEPTH_OF_FIELD 8
# define TEXTURE_DIMENSIONS 64

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
void	raycasting_south(t_env *env, t_ray *ray_coords);
/**
 * @brief The raycasting_south and north functions are used to check if a wall
 * above or below the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_north(t_env *env, t_ray *ray_coords);
/**
 * @brief The raycasting_east and west functions are used to check if a wall
 * to the left or right of the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_east(t_env *env, t_ray *ray_coords);
/**
 * @brief The raycasting_east and west functions are used to check if a wall
 * to the left or right of the player (on the map) was hit by the ray
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's data
 * @param map_coords The hitpoint data
 */
void	raycasting_west(t_env *env, t_ray *ray_coords);
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
/**
 * @brief The draw_3d function is used to draw the walls from the ray hit
 * coordinates
 * 
 * @param env A pointer to the main env struct
 * @param ray_coords The current ray's coordinates
 * @param final_dist The distance between the player and the ray endpoint
 * @param i The ray's angle
 */
void	draw_3d(t_env *env, t_ray ray_coords, float final_dist, int i);

/*			Looping			*/
/**
 * @brief The main loop function is used by the mlx loop_hook
 * it handles player input and calls the rendering function to create a frame
 * to display every 1/FPS seconds.
 * 
 * @param param Used to pass the env struct through the loop_hook
 */
void	main_loop(void	*param);

/*			Utils			*/
/**
 * @brief Get the largest column size from the map
 * 
 * @param env A pointer to main env struct
 * @return int The size of the largest column
 */
int		get_largest_map_column(t_env *env);


void	render_wall(t_env *env, int x);
void	set_ray_dir(t_env *env, int x);
void	raycast_start(t_env *env);
void	raycast_loop(t_env *env);
void	calculate_wall_distance(t_env *env, int *wall_height, int *texture_x);
void	draw_wall_line(t_env *env, int x, int wall_height, int texture_x);
t_limits	calculate_limits(int wall_height);
void	init_ray(t_env *env);
void	player_init_north(t_coord *coords, int i, int j);
void	player_init_south(t_coord *coords, int i, int j);
void	player_init_east(t_coord *coords, int i, int j);
void	player_init_west(t_coord *coords, int i, int j);

#endif