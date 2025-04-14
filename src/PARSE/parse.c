#include "Cube3d.h"

void	*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
int *width, int *height);

bool ft_handleline(char *line, t_env *env)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_strcmp(line + i, "NO ./") == 0)
		env->NO_image = mlx_xpm_file_to_image(env->mlx, FILENAME,
				IMAGE_WIDTH, IMAGE_HEIGHT);
	else if (ft_strcmp(line + i, "SO ./") == 0)
		env->SO_image = mlx_xpm_file_to_image(env->mlx, FILENAME,
				IMAGE_WIDTH, IMAGE_HEIGHT);
	else if (ft_strcmp(line + i, "WE ./") == 0)
		env->WE_image = mlx_xpm_file_to_image(env->mlx, FILENAME,
				IMAGE_WIDTH, IMAGE_HEIGHT);
	else if (ft_strcmp(line + i, "EA ./") == 0)
		env->EA_image = mlx_xpm_file_to_image(env->mlx, FILENAME,
				IMAGE_WIDTH, IMAGE_HEIGHT);
	else if (line[i] == 'C')
		env->C_color = COLOR;
	else if (line[i] == 'F')
		env->F_color = COLOR;
	else 
		return (false); 
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
			return (parse_error(INT_MAP_INVALID_PARAM));
	}
	close(fd);
	return (true);
}
