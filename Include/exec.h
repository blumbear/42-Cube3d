#ifndef EXEC_H
# define EXEC_H

# define PI 3.1415926535
# define HEIGHT 512
# define WIDTH 1024
# define FPS 60
# define CEILING_COLOR 0x0000FFFF
# define FLOOR_COLOR 0x7B7B7BFF

/*			Initialization			*/
void	exec_init(t_env *env);

/*			Rendering			*/
void	render_frame(t_env *frame);
void	draw_background(t_env *env);

/*			Looping			*/
void	main_loop(void	*param);

/*			Utils			*/
void	print_player_coords(t_coord *coords);



#endif