#ifndef PARSE_H
# define PARSE_H

#include "Cub3d.h"

bool			check_map_line(char *line, t_env *env, int y);
bool			check_map_first_line(char *line, bool *map);
t_parse_flag	map_test(char *line, int i);
int				read_map(int depth, t_env *env, int fd, char *line);
bool			parse(char *file, t_env *env, bool map);
void			set_map_size(t_env *env);
bool			map_check(t_env *env);
bool			floodfill(char **map, int x, int y, int *map_size);

# endif