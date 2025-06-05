/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:09 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/05 16:49:46 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define HEIGHT 512
# define WIDTH 1024
# define FPS 60
# define CEILING_COLOR 0x0000FFFF
# define FLOOR_COLOR 0x7B7B7BFF
# define ROTATION_SPEED 0.1
# define MOVEMENT_SPEED 0.1
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
void	init_ray(t_env *env);
void	player_init_north(t_coord *coords, int i, int j);
void	player_init_south(t_coord *coords, int i, int j);
void	player_init_east(t_coord *coords, int i, int j);
void	player_init_west(t_coord *coords, int i, int j);

/*			Rendering			*/
/**
 * @brief The render_frame function calls upon many other rendering fuctions
 * and puts everything together to have a nice lttle image on your screen
 * 
 * @param env A pointer to the main env struct
 */
void	render_frame(t_env *env);
void	render_wall(t_env *env, int x);
void	raycast_start(t_env *env);
void	raycast_loop(t_env *env);
void	calculate_wall_distance(t_env *env, int *wall_height, int *texture_x);
void	draw_wall_line(t_env *env, int x, int wall_height, int texture_x);
/**
 * @brief The draw_background function is used to draw the "background" (floor 
 * and ceiling) of the frame
 * 
 * @param env A pointer to the main env struct
 */
void	draw_background(t_env *env);

/*			Gameplay			*/
/**
 * @brief The main loop function is used by the mlx loop_hook
 * it handles player input and calls the rendering function to create a frame
 * to display every 1/FPS seconds.
 * 
 * @param param Used to pass the env struct through the loop_hook
 */
void	main_loop(void	*param);
void	rotate_camera(t_env *env, double angle);
void	move_right(t_env *env);
void	move_left(t_env *env);
void	move_backward(t_env *env);
void	move_forward(t_env *env);

/*			Utils			*/
/**
 * @brief Get the largest column size from the map
 * 
 * @param env A pointer to main env struct
 * @return int The size of the largest column
 */
int			get_largest_map_column(t_env *env);
void		set_ray_dir(t_env *env, int x);
t_limits	calculate_limits(int wall_height);

#endif