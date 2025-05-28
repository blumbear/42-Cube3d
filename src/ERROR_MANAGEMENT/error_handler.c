#include "Cub3d.h"

bool parse_error(int error_flag)
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
	else if (error_flag == INT_MAP_IS_NOT_SURROUNDED)
		ft_putstr_fd(STR_MAP_IS_NOT_SURROUNDED, STDERR_FILENO);
	else if (error_flag == INT_WRONG_F_RGB)
		ft_putstr_fd(STR_WRONG_F_RGB, STDERR_FILENO);
	else if (error_flag == INT_WRONG_C_RGB)
		ft_putstr_fd(STR_WRONG_C_RGB, STDERR_FILENO);
	return (false);
}

int arg_error(int error_flag)
{
	ft_putstr_fd(ARGUMENT_ERROR_MSG, STDERR_FILENO);
	if (error_flag == INT_TOO_FEW_ARGUMENT)
		ft_putstr_fd(STR_TOO_FEW_ARGUMENT, STDERR_FILENO);
	else if (error_flag == INT_TOO_MANY_ARGUMENT)
		ft_putstr_fd(STR_TOO_MANY_ARGUMENT, STDERR_FILENO);
	else if (error_flag == INT_INVALID_FILE_FORMAT)
		ft_putstr_fd( STR_INVALID_FILE_FORMAT, STDERR_FILENO);
	else if (error_flag == INT_INVALID_FILE)
		ft_putstr_fd(STR_INVALID_FILE, STDERR_FILENO);
	return (EXIT_SUCCESS);
}
