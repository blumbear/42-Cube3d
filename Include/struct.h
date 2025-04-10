#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	t_coord	player_coord;
	bool	player;
} t_env;

typedef struct s_coord
{
	int	x;
	int	y;
} t_coord;

# endif