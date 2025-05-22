#ifndef STRUCT_H
# define STRUCT_H

# define IMAGE_WIDTH 24
# define IMAGE_HEIGHT 24
# define FILENAME "Fichier à mettre"
# define COLOR "Couleur à mettre"

typedef enum s_parse_flag
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	NOTHING
} t_parse_flag ;

typedef struct s_coord
{
	double	pos_x;
	double	pos_y;
	double	delta_x;
	double	delta_y;
	double	angle;
}				t_coord;

typedef struct s_env
{
//--------------------
	mlx_t		*mlx;
	mlx_image_t	*window;
//--------------------
	mlx_texture_t		*NO_image;
	mlx_texture_t		*SO_image;
	mlx_texture_t		*WE_image;
	mlx_texture_t		*EA_image;
	bool		texture_fill;
//--------------------
	char		*F_color;
	char		*C_color;
	bool		color_fill;
	//--------------------
	char		**map;
	int			*map_size;
	int			map_width;
	int			map_height;
	bool		map_fill;
	//--------------------
	t_coord		*player_coord;
	bool		player;
//--------------------
} t_env;

# endif