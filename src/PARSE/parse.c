#include "Cube3d.h"

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
int *width, int *height);

bool ft_iswspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\b' || c == '\v');
}

char	*fill_buffer(char *line, t_mapflag flag)
{
	int		i;
	char	*buffer;

	i = 0;
	if (flag <= 3)
		line += 3;
	else 
		line += 2;
	buffer = ft_calloc(ft_strlen(line), sizeof(char));
	while (line[i] && !is_whitespace(line[i]))
	{
		buffer[i] = line[i];
		i++;
	}
	ft_printf("buffer = %s\n", buffer);
	return (buffer);
}

void	fill_struct(char *buffer, t_mapflag flag, t_env *env)
{
	int *img_w;
	int *img_h;

	img_w =	ft_calloc(1, sizeof(int));
	img_h =	ft_calloc(1, sizeof(int));
	img_w = (int *)IMAGE_WIDTH;
	img_h = (int *)IMAGE_HEIGHT;
	if (flag == NO)
		env->NO_image = mlx_xpm_file_to_image(env->mlx, buffer, img_w, img_h);
	else if (flag == SO)
		env->SO_image = mlx_xpm_file_to_image(env->mlx, buffer, img_w, img_h);
	else if (flag == WE)
		env->WE_image = mlx_xpm_file_to_image(env->mlx, buffer, img_w, img_h);
	else if (flag == EA)
		env->EA_image = mlx_xpm_file_to_image(env->mlx, buffer, img_w, img_h);
	else if (flag == F)
		env->F_color = buffer;
	else if (flag == C)
		env->C_color = buffer;
}

bool ft_handleline(char *line, t_env *env)
{
	int			i;
	char		*buffer;
	t_mapflag	flag;

	i = 0;
	while (ft_iswspace(line[i]) && line[i])
		i++;
	if (ft_strncmp(line + i, "NO ./", 5) == 0)
		flag = NO;
	else if (ft_strncmp(line + i, "SO ./", 5) == 0)
		flag = SO;
	else if (ft_strncmp(line + i, "WE ./", 5) == 0)
		flag = WE;
	else if (ft_strncmp(line + i, "EA ./", 5) == 0)
		flag = EA;
	else if (line[i] == 'C' && line[i + 1] == ' ')
		flag = C;
	else if (line[i] == 'F' && line[i + 1] == ' ')
		flag = F;
	else if (is_whitespace(line[i]) || line[i] == '\n')
		return (true);
	else
		return (false);
	buffer = fill_buffer(line + i, flag);
	fill_struct(buffer, flag, env);
	free(buffer);
	return (true);
}

bool parse(char *file, t_env *env)
{
	int		fd;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (false);
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (ft_handleline(buffer, env) == false)
		{
			free(buffer);
			close(fd);
			return (parse_error(INT_MAP_INVALID_PARAM));
		}
		free(buffer);
		buffer = (get_next_line(fd));
	}
	close(fd);
	return (true);
}
