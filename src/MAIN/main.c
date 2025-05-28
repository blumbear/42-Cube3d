/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:15:06 by tom               #+#    #+#             */
/*   Updated: 2025/05/28 11:37:22 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

bool check_file_format(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".cub") != 0)
		return (false);
	return (true);
}

void	init_env(t_env *env)
{
	env->texture_fill = -3;
	env->F_color = ft_calloc(12, sizeof(char));
	env->C_color = ft_calloc(12, sizeof(char));
	env->color_fill = -1;
	env->map = NULL;
	env->map_size = NULL;
	env->map_fill = false;
	env->map_max_width = 0;
	env->player_coord = ft_calloc(1, sizeof(t_coord));
	env->player_coord->x = -1;
	env->player_coord->y = -1;
	env->player = false;
	env->NO_image = NULL;
	env->SO_image = NULL;
	env->WE_image = NULL;
	env->EA_image = NULL;
}

int end_prog(t_env *env)
{
	if (env->NO_image)
		free(env->NO_image);
	if (env->SO_image)
		free(env->SO_image);
	if (env->WE_image)
		free(env->WE_image);
	if (env->EA_image)
		free(env->EA_image);
	if (env->C_color)
		free(env->C_color);
	if (env->F_color)
		free(env->F_color);
	if (env->map)
		ft_free_double_array(env->map);
	if (env->map_size)
		free(env->map_size);
	if (env->player_coord)
		free(env->player_coord);
	return (EXIT_SUCCESS);
}

bool	floodfill(char **map, int x, int y, int *map_size)
{
	if (map[y][x] != '1')
	{
		if (map_size[y + 1] < x + 1 || map_size[y - 1] < x + 1)
			return (false);
		else if (map[y + 1][x] == ' ' || map[y + 1][x] == '\n')
			return (false);
		else if (map[y - 1][x] == ' ' || map[y - 1][x] == '\n')
			return (false);
		else if (map[y][x + 1] == ' ' || map[y][x + 1] == '\n')
			return (false);
		else if (map[y][x - 1] == ' ' || map[y][x - 1] == '\n')
			return (false);
	}
	map[y][x] *= -1;
	if (map[y + 1][x] != '1' && map[y + 1][x] > 0)
		if (floodfill(map, x, y + 1, map_size) == false)
			return (false);
	if (map[y - 1][x] != '1' && map[y - 1][x] > 0)
		if (floodfill(map, x, y - 1, map_size) == false)
			return (false);
	if (map[y][x + 1] != '1' && map[y][x + 1] > 0)
		if (floodfill(map, x + 1, y, map_size) == false)
			return (false);
	if (map[y][x - 1] != '1' && map[y][x - 1] > 0)
		if (floodfill(map, x - 1, y, map_size) == false)
			return (false);
	return (true);
}

bool	map_check(t_env *env)
{
	// int	i;
	// int	j;

	if (!floodfill(env->map, env->player_coord->x, env->player_coord->y, env->map_size))
		return (parse_error(INT_MAP_IS_NOT_SURROUNDED));
	// i = -1;
	// while (env->map[++i])
	// {
	// 	j = -1;
	// 	while (env->map[i][++j])
	// 		if (env->map[i][j] <= 0)
	// 			env->map[i][j] *= -1;
	// }
	return (true);
}

void	set_map_size(t_env *env)
{
	int i;
	int tmp;

	i = 0;
	while (env->map[i])
		i++;
	env->map_size = ft_calloc(i, sizeof(int));
	i = -1;
	while (env->map[++i])
	{
		tmp = ft_strlen(env->map[i]);
		if (tmp > env->map_max_width)
			env->map_max_width = tmp;
		env->map_size[i] = tmp;
		ft_printf("%d\n", env->map_size[i]);
	}
	return ;
}


int main(int ac, char **av)
{
	t_env env;
	
	if (ac < 2)
		return (arg_error(INT_TOO_FEW_ARGUMENT));
	else if (ac > 2)
		return (arg_error(INT_TOO_MANY_ARGUMENT));
	else if (check_file_format(av[1]) == false)
		return (arg_error(INT_INVALID_FILE_FORMAT));
	init_env(&env);
	if (parse(av[1], &env, false) == false)
		return (end_prog(&env));
	set_map_size(&env);
	ft_printf("map_max_width = %d\n", env.map_max_width);
	if (map_check(&env) == false)
		return (end_prog(&env));
	ft_print_double_array(env.map, 0);
 	return (end_prog(&env));
}