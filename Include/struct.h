/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:37 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/05 16:51:51 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define IMAGE_WIDTH 24
# define IMAGE_HEIGHT 24
# define FILENAME "Fichier à mettre"
# define COLOR "Couleur à mettre"
# define DEG_TO_RAD 0.0174533
# define CUBE_SIZE 64

typedef enum s_parse_flag
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	NOTHING
}			t_parse_flag;

typedef struct s_limits
{
	int	beginning;
	int	end;
}				t_limits;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	camera_x;
	int		map_x;
	int		map_y;
	int		x_offset;
	int		y_offset;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_dist;
	int		step_x;
	int		step_y;
	int		side;
}				t_ray;

typedef struct s_coord
{
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_coord;

typedef struct s_env
{
//--------------------
	mlx_t			*mlx;
	mlx_image_t		*window;
//--------------------
	mlx_texture_t	*no_image;
	mlx_texture_t	*so_image;
	mlx_texture_t	*we_image;
	mlx_texture_t	*ea_image;
	bool			texture_fill;
//--------------------
	char			*f_color;
	char			*c_color;
	bool			color_fill;
	//--------------------
	char			**map;
	int				*map_size;
	int				map_width;
	int				map_height;
	bool			map_fill;
	//--------------------
	t_coord			*player_coord;
	bool			player;
	//--------------------
	t_ray			ray_coords;
//--------------------
}				t_env;

#endif