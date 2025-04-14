#ifndef STRUCT_H
# define STRUCT_H

# define IMAGE_WIDTH 24
# define IMAGE_HEIGHT 24
# define FILENAME "Fichier à mettre"
# define COLOR "Couleur à mettre"

typedef enum s_mapflag
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
} t_mapflag ;

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
//--------------------
	char	*F_color;
	char	*C_color;
//--------------------
	char	**map;
//--------------------
	t_coord	player_coord;
	bool	player;
//--------------------
} t_env;

# endif