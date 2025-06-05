/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:13:19 by tom               #+#    #+#             */
/*   Updated: 2025/06/05 16:26:57 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

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
	else if (error_flag == INT_MAP_IS_NOT_SURROUNDED)
		ft_putstr_fd(STR_MAP_IS_NOT_SURROUNDED, STDERR_FILENO);
	else if (error_flag == INT_WRONG_F_RGB)
		ft_putstr_fd(STR_WRONG_F_RGB, STDERR_FILENO);
	else if (error_flag == INT_WRONG_C_RGB)
		ft_putstr_fd(STR_WRONG_C_RGB, STDERR_FILENO);
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
	if (env->no_image)
		free(env->no_image);
	if (env->so_image)
		free(env->so_image);
	if (env->we_image)
		free(env->we_image);
	if (env->ea_image)
		free(env->ea_image);
	if (env->c_color)
		free(env->c_color);
	if (env->f_color)
		free(env->f_color);
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
	if (env->mlx)
	{
		mlx_close_window(env->mlx);
		mlx_terminate(env->mlx);
	}
	end_prog(env);
	exit(EXIT_SUCCESS);
}
