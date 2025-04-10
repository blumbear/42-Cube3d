#include "Cube3d.h"

int parse_error(int error_flag)
{
	if (error_flag == true)
		return (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int arg_error(int error_flag)
{
	if (error_flag == TOO_FEW_ARGUMENT)
		ft_putstr_fd("Too few argument.\nUsage: ./Cube3d <test>.cub\n",
			STDERR_FILENO);
	else if (error_flag == TOO_MANY_ARGUMENT)
		ft_putstr_fd("Too many argument.\nUsage: ./Cube3d <test>.cub\n",
			STDERR_FILENO);
	else if (error_flag == INVALID_FILE_FORMAT)
		ft_putstr_fd("Invalid file format.\nThe file format must be \".cub\"\n",
			STDERR_FILENO);
	else if (error_flag == INVALID_FILE)
		ft_putstr_fd("The File don't exist or can't be open\n", STDERR_FILENO);
	return (EXIT_SUCCESS);
}
