#include "Cube3d.h"

bool	parse_error(int error_flag)
{
	ft_putstr_fd(PARSE_ERROR_MSG, STDERR_FILENO);
	if (error_flag == INT_MAP_INVALID_PARAM)
		ft_putstr_fd(STR_MAP_INVALID_PARAM, STDERR_FILENO);
	else if (error_flag == INT_MAP_INVALID_PARAM)
		ft_putstr_fd(STR_MAP_INVALID_PARAM, STDERR_FILENO);
	else if (error_flag == INT_MAP_INVALID_CHAR)
		ft_putstr_fd(STR_MAP_INVALID_CHAR, STDERR_FILENO);
	else if (error_flag == INT_DOUBLE_PLAYER_IN_MAP)
		ft_putstr_fd(STR_DOUBLE_PLAYER_IN_MAP, STDERR_FILENO);
	else if (INT_MAP_IS_NOT_SURROUNDED)
		ft_putstr_fd(STR_MAP_IS_NOT_SURROUNDED, STDERR_FILENO);
	return (false);
}

int	arg_error(int error_flag)
{
	ft_putstr_fd(ARGUMENT_ERROR_MSG, STDERR_FILENO);
	if (error_flag == INT_TOO_FEW_ARGUMENT)
		ft_putstr_fd(STR_TOO_FEW_ARGUMENT, STDERR_FILENO);
	else if (error_flag == INT_TOO_MANY_ARGUMENT)
		ft_putstr_fd(STR_TOO_MANY_ARGUMENT, STDERR_FILENO);
	else if (error_flag == INT_INVALID_FILE_FORMAT)
		ft_putstr_fd(STR_INVALID_FILE_FORMAT, STDERR_FILENO);
	else if (error_flag == INT_INVALID_FILE)
		ft_putstr_fd(STR_INVALID_FILE, STDERR_FILENO);
	return (EXIT_SUCCESS);
}

int	end_prog(t_env *env)
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

void	clean_exit(t_env *env)
{
	mlx_close_window(env->mlx);
	end_prog(env);
	mlx_terminate(env->mlx);
	exit(EXIT_SUCCESS);
}
