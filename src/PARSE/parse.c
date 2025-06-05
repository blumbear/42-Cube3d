/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:34 by tom               #+#    #+#             */
/*   Updated: 2025/06/05 17:09:50 by bchedru          ###   ########.fr       */
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

char	*rgb_to_hex_char(char *buffer)
{
	char	*res;
	char	**tmp_split;
	char	*tmp;
	int		int_tmp;
	int		i;

	i = -1;
	while (buffer[++i])
		if (!ft_isdigit(buffer[i]) && buffer[i] != ',')
			return (NULL);
	res = ft_calloc(10, sizeof(char));
	res[0] = '0';
	res[1] = 'x';
	i = -1;
	tmp_split = ft_split(buffer, ',');
	while (++i < 3)
	{
		int_tmp = ft_atoi(tmp_split[i]);
		tmp = int_to_hex(int_tmp, "0123456789ABCDEF");
		ft_strlcat(res, tmp, 9);
		free(tmp);
	}
	ft_free_double_array(tmp_split);
	res[9] = 0;
	return (res);
}

bool	fill_struct(char *buffer, t_parse_flag flag, t_env *env)
{
	if (flag == NO)
		env->no_image = mlx_load_png(buffer);
	else if (flag == SO)
		env->so_image = mlx_load_png(buffer);
	else if (flag == WE)
		env->we_image = mlx_load_png(buffer);
	else if (flag == EA)
		env->ea_image = mlx_load_png(buffer);
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
		return (false);
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
