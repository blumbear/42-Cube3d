#ifndef PARSE_H
# define PARSE_H

#include "Cube3d.h"

bool			check_map_line(char *line);
bool			check_map_first_line(char *line, bool *map);
t_parse_flag	map_test(char *line, int i);
int				read_map(int depth, t_env *env, int fd, char *line);
bool			parse(char *file, t_env *env, bool map);

# endif