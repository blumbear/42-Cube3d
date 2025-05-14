/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:40:34 by tom               #+#    #+#             */
/*   Updated: 2025/04/23 13:46:10 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

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
	while(is_whitespace(line[i]))
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

void	fill_struct(char *buffer, t_parse_flag flag, t_env *env)
{
	int img_w;
	int img_h;

	img_w = IMAGE_WIDTH;
	img_h = IMAGE_HEIGHT;
	if (flag == NO)
		env->NO_image = mlx_xpm_file_to_image(env->mlx, buffer, &img_w, &img_h);
	else if (flag == SO)
		env->SO_image = mlx_xpm_file_to_image(env->mlx, buffer, &img_w, &img_h);
	else if (flag == WE)
		env->WE_image = mlx_xpm_file_to_image(env->mlx, buffer, &img_w, &img_h);
	else if (flag == EA)
		env->EA_image = mlx_xpm_file_to_image(env->mlx, buffer, &img_w, &img_h);
	else if (flag == F)
		ft_strcpy(env->F_color, buffer);
	else if (flag == C)
		ft_strcpy(env->C_color, buffer);
}

bool ft_handleline(char *line, t_env *env, bool *map)
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
			return (false);
	}
	buffer = fill_buffer(line + i, flag);
	if (!buffer)
		return (false);
	fill_struct(buffer, flag, env);
	free(buffer);
	return (true);
}

bool parse(char *file, t_env *env, bool map)
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
			return (parse_error(INT_MAP_INVALID_PARAM));
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
