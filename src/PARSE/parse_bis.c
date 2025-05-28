/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:17 by tom               #+#    #+#             */
/*   Updated: 2025/05/14 15:07:09 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

bool	check_map_line(char *line, t_env *env, int y)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (ft_strchr("01NSWE\n ", line[i]) == NULL)
			return (parse_error(INT_MAP_INVALID_CHAR));
		if (line[i] == 'N' || line[i] == 'W'
				|| line[i] == 'E' || line[i] == 'O')
		{
			if (env->player_coord->x != -1)
				return (parse_error(INT_DOUBLE_PLAYER_IN_MAP));
			env->player_coord->x = i;
			env->player_coord->y = y;
		}
	}
	return (true);
}

bool	check_map_first_line(char *line, bool *map)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != '\n')
			return (false);
	}
	*map = true;
	return (true);
}

t_parse_flag map_test(char *line, int i)
{
	if (ft_strncmp(line + i, "NO", 2) == 0)
		return (NO);
	else if (ft_strncmp(line + i, "SO", 2) == 0)
		return (SO);
	else if (ft_strncmp(line + i, "WE", 2) == 0)
		return (WE);
	else if (ft_strncmp(line + i, "EA", 2) == 0)
		return (EA);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		return (F);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		return (C);
	return (NOTHING);
}

int	read_map(int depth, t_env *env, int fd, char *line)
{
	if (!line)
		line = get_next_line(fd);
	if (line == NULL)
	{
		env->map = ft_calloc(depth + 1, sizeof(char *));
		env->map[depth] = NULL;
		return (true);
	}
	if (check_map_line(line, env, depth) == false)
	{
		free(line);
		return (-1);
	}
	if (read_map(depth + 1, env, fd, NULL) == -1)
	{
		free(line);
		return (-1);
	}
	env->map[depth] = line;
	return (true);
}
