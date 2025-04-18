#include "Cube3d.h"

bool ft_iswspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\b' || c == '\v');
}

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
	buffer = ft_calloc(j, sizeof(char));
	j = 0;
	while (line[i] && !is_whitespace(line[i]))
		buffer[j++] = line[i++];
	buffer[j] = '\0';
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

bool ft_handleline(char *line, t_env *env, bool *map)
{
	int				i;
	char			*buffer;
	t_parse_flag	flag;

	i = 0;
	while (ft_iswspace(line[i]) && line[i])
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


int	read_map(int depth, t_env *env, int fd, char *line)
{
	if (!line)
		line = get_next_line(fd);
	if (line == NULL)
	{
		env->map = ft_calloc(depth + 1, sizeof(char *));
		env->map[depth] = NULL;
		return (false);
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

bool parse(char *file, t_env *env)
{
	int		fd;
	char	*buffer;
	bool	map;

	map = false;
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
		if (map == false)
		{
			free(buffer);
			buffer = get_next_line(fd);
		}
	}
	if (!read_map(0, env, fd, buffer))
		return (parse_error(INT_MAP_INVALID_CHAR));
	close(fd);
	return (true);
}
