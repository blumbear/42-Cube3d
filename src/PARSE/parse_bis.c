/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:17 by tom               #+#    #+#             */
/*   Updated: 2025/04/18 18:41:56 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

bool	check_map_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
				&& line[i] != 'O' && line[i] != 'E' && line[i] != 'W'
				&& line[i] != ' ' && line[i] != '\n')
			return (false);
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
	if (check_map_line(line) == false)
	{
		free(line);
		parse_error(INT_MAP_INVALID_CHAR);
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
