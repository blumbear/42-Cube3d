/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:34 by tom               #+#    #+#             */
/*   Updated: 2025/06/11 15:42:46 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

char	*fill_buffer(char *line, t_parse_flag flag)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	if (flag <= 3)
		line += 2;
	else
		line += 1;
	while (is_whitespace(line[i]))
		i++;
	if ((line[i] != '.' || line[i + 1] != '/') && flag <= 3)
		return (NULL);
	j = i;
	while (line[j] && !is_whitespace(line[j]))
		j++;
	buffer = ft_calloc(j + 1, sizeof(char));
	j = 0;
	while (line[i] && !is_whitespace(line[i]))
		buffer[j++] = line[i++];
	buffer[j + 1] = '\0';
	return (buffer);
}

bool	fill_struct(char *buffer, t_parse_flag flag, t_env *env)
{
	if (flag == NO)
	{
		env->no_image = mlx_load_png(buffer);
		if (!env->no_image)
			return (parse_error(INT_IMAGE_NOT_FOUND));
	}
	else if (flag == SO)
	{
		env->so_image = mlx_load_png(buffer);
		if (!env->so_image)
			return (parse_error(INT_IMAGE_NOT_FOUND));
	}
	else if (flag == WE)
	{
		env->we_image = mlx_load_png(buffer);
		if (!env->we_image)
			return (parse_error(INT_IMAGE_NOT_FOUND));
	}
	else if (flag == EA)
	{
		env->ea_image = mlx_load_png(buffer);
		if (!env->ea_image)
			return (parse_error(INT_IMAGE_NOT_FOUND));
	}
	return (rgb_check(buffer, flag, env));
}

bool	ft_handleline(char *line, t_env *env, bool *map)
{
	int				i;
	char			*buffer;
	t_parse_flag	flag;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\b' || line[i] == '\v'))
		i++;
	flag = map_test(line, i);
	if (flag == NOTHING)
	{
		if (is_whitespace(line[i]))
			return (true);
		else if (check_map_first_line(line, map))
			return (true);
		else
			return (parse_error(INT_MAP_INVALID_PARAM));
	}
	buffer = fill_buffer(line + i, flag);
	if (!buffer)
		return (false);
	if (!fill_struct(buffer, flag, env))
		return (free(buffer), false);
	free(buffer);
	return (true);
}

bool	parse(char *file, t_env *env, bool map)
{
	int		fd;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	buffer = get_next_line(fd);
	while (buffer && map == false)
	{
		if (ft_handleline(buffer, env, &map) == false)
		{
			free(buffer);
			close(fd);
			return (false);
		}
		else if (map == false)
		{
			free(buffer);
			buffer = get_next_line(fd);
		}
	}
	if (read_map(0, env, fd, buffer) <= 0)
		return (false);
	close(fd);
	return (true);
}
