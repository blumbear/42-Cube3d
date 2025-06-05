/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:52:58 by tom               #+#    #+#             */
/*   Updated: 2025/05/29 23:14:32 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	check_line_size(int *map_size, int x, int y, char **map)
{
	if (y == 0)
		return (false);
	else if (map_size[y + 1] < x + 1 || map_size[y - 1] < x + 1)
		return (false);
	else if (map[y + 1][x] == ' ' || map[y + 1][x] == '\n')
		return (false);
	else if (map[y - 1][x] == ' ' || map[y - 1][x] == '\n')
		return (false);
	else if (map[y][x + 1] == ' ' || map[y][x + 1] == '\n')
		return (false);
	else if (map[y][x - 1] == ' ' || map[y][x - 1] == '\n')
		return (false);
	return (true);
}

bool	floodfill(char **map, int x, int y, int *map_size)
{
	if (map[y][x] != '1')
		if (check_line_size(map_size, x, y, map) == false)
			return (false);
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
	int	i;
	int	j;

	if (!floodfill(env->map, env->player_coord->pos_x, env->player_coord->pos_y
			, env->map_size))
		return (parse_error(INT_MAP_IS_NOT_SURROUNDED));
	i = -1;
	while (env->map[++i])
	{
		j = -1;
		while (env->map[i][++j])
			if (env->map[i][j] < 0)
				env->map[i][j] *= -1;
	}
	return (true);
}

void	set_map_size(t_env *env)
{
	int	i;
	int	tmp;

	i = 0;
	while (env->map[i])
		i++;
	env->map_size = ft_calloc(i + 1, sizeof(int));
	i = -1;
	while (env->map[++i])
	{
		tmp = ft_strlen(env->map[i]);
		if (tmp > env->map_width)
			env->map_width = tmp;
		env->map_size[i] = tmp;
	}
	env->map_size[i] = 0;
	return ;
}
