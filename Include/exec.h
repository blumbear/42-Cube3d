/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:09 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/11 17:32:07 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# define HEIGHT 512
# define WIDTH 1024
# define FPS 60
# define ROTATION_SPEED 0.1
# define MOVEMENT_SPEED 0.1
# define TEXTURE_DIMENSIONS 64
# define CUBE_SIZE 64

/*			Initialization			*/

/**
 * @brief The exec_init function simply initializes essential variables and
 * kickstarts the mlx42
 * 
 * @param env A pointer to the main env struct
 */
void			exec_init(t_env *env);
/**
 * @brief This function initializes the player's coordinates according to its
 * placement on the map.
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 * @param dir The direction the player is facing when the game launches
 */
void			init_player_coords(t_coord *coords, int i, int j, char dir);
/**
 * @brief Initializes a ray's coordinates to default values
 * 
 * @param env A pointer to the main env struct
 */
void			init_ray(t_env *env);
/**
 * @brief Initializes the player coords when he is facig north
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 */
void			player_init_north(t_coord *coords, int i, int j);
/**
 * @brief Initializes the player coords when he is facig south
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 */
void			player_init_south(t_coord *coords, int i, int j);
/**
 * @brief Initializes the player coords when he is facig east
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 */
void			player_init_east(t_coord *coords, int i, int j);
/**
 * @brief Initializes the player coords when he is facig west
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 */
void			player_init_west(t_coord *coords, int i, int j);
/**
 * @brief Initializes the player coords when he is facig east
 * 
 * @param coords The coord struct to be initialized
 * @param i The x coordinate
 * @param j The y coordinate
 */

/*			Rendering			*/
/**
 * @brief The render_frame function calls upon many other rendering fuctions
 * and puts everything together to have a nice lttle image on your screen
 * 
 * @param env A pointer to the main env struct
 */
void			render_frame(t_env *env);
/**
 * @brief The render_wall function starts the raycasting process. First we 
 * determine the ray's direction.
 * 
 * @param env A pointer to the main env struct
 * @param x The x coordinate of current pixel to be rendered
 */
void			render_wall(t_env *env, int x);
/**
 * @brief Initializes further ray coordinates depending on its direction
 * 
 * @param env A pointer to the main env struct
 */
void			raycast_start(t_env *env);
/**
 * @brief Main raycasting loop, continues the ray until a wall is hit
 * 
 * @param env A pointer to the main env struct
 */
void			raycast_loop(t_env *env);
/**
 * @brief Uses the ray's values to determine at what height the wall is to be
 * rendered.
 * 
 * @param env A pointer to the main env struct
 * @param wall_height The variable that will store the result
 * @param texture_x The variable that will store what pixel to grab on the
 * texture
 */
void			calculate_wall_distance(t_env *env, int *wall_height,
					int *texture_x);
/**
 * @brief The draw_wall_line function is used to draw a wall's x column (and not
 * line, yes I am retarded)
 * 
 * @param env A pointer to the main env struct
 * @param x The ray's x coordinate
 * @param wall_height The wall's height to be reached
 * @param texture_x The x coordinate to get pixel from the texture
 */
void			draw_wall_line(t_env *env, int x, int wall_height,
					int texture_x);

/**
 * @brief The draw_background function is used to draw the "background" (floor 
 * and ceiling) of the frame
 * 
 * @param env A pointer to the main env struct
 */
void			draw_background(t_env *env);

/*			Gameplay			*/
/**
 * @brief The main loop function is used by the mlx loop_hook
 * it handles player input and calls the rendering function to create a frame
 * to display every 1/FPS seconds.
 * 
 * @param param Used to pass the env struct through the loop_hook
 */
void			main_loop(void	*param);
/**
 * @brief This function is used to rotate the player's camera
 * 
 * @param env A pointer to the main env struct
 * @param angle The number of degrees to rotate the camera
 */
void			rotate_camera(t_env *env, double angle);
/**
 * @brief This function is used to move the player to the right
 * 
 * @param env A pointer to the main env struct
 */
void			move_right(t_env *env);
/**
 * @brief This function is used to move the player to the left
 * 
 * @param env A pointer to the main env struct
 */
void			move_left(t_env *env);
/**
 * @brief This function is used to move the player backwards
 * 
 * @param env A pointer to the main env struct
 */
void			move_backward(t_env *env);
/**
 * @brief This function is used to move the player forwards
 * 
 * @param env A pointer to the main env struct
 */
void			move_forward(t_env *env);

/*			Utils			*/
/**
 * @brief Get the largest column size from the map
 * 
 * @param env A pointer to main env struct
 * @return int The size of the largest column
 */
int				get_largest_map_column(t_env *env);
/**
 * @brief Initializes the ray's camera, dir, map, and delta values based on the
 * current x render value
 * 
 * @param env A pointer to the main env struct
 * @param x The current x render value (on-screen)
 */
void			set_ray_dir(t_env *env, int x);
/**
 * @brief Calculates the wall's top and bottom pixel coordinates
 * 
 * @param wall_height The wall's height
 * @return t_limits The bottom and top coordinates
 */
t_limits		calculate_limits(int wall_height);
/**
 * @brief This function uses the ray's direction to determine which texture to
 * use
 * 
 * @param env A pointer to the main env struct
 * @return mlx_texture_t* The chosen texture
 */
mlx_texture_t	*select_texture(t_env *env);
/**
 * @brief Uses the already calculated coordinates to navigate the texture and
 * exract the correct pixel's color
 * 
 * @param texture The texture variable to be used
 * @param texture_x The chosen pixel's x coordinate
 * @param texture_y The chosen pixel's y coordinate
 * @return uint32_t The rgba value of the pixel
 */
uint32_t		get_pixel_color(mlx_texture_t *texture, int texture_x,
					int texture_y);

#endif