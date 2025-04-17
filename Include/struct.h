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
	int	x;
	int	y;
} t_coord;

typedef struct s_env
{
//--------------------
	void	*mlx;
//--------------------
	void	*NO_image;
	void	*SO_image;
	void	*WE_image;
	void	*EA_image;
	bool	texture_fill;
//--------------------
	char	*F_color;
	char	*C_color;
	bool	color_fill;
	//--------------------
	char	**map;
	bool	map_fill;
	//--------------------
	t_coord	player_coord;
	bool	player;
//--------------------
} t_env;

# endif