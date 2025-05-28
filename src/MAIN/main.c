/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:15:06 by tom               #+#    #+#             */
/*   Updated: 2025/05/28 18:49:44 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	check_file_format(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".cub") != 0)
		return (false);
	return (true);
}

void	init_env(t_env *env)
{
	env->texture_fill = -3;

	env->F_color = NULL;
	env->C_color = NULL;
	env->color_fill = -1;
	env->map = NULL;
	env->map_size = NULL;
	env->map_fill = false;
	env->map_width = 0;
	env->player_coord = ft_calloc(1, sizeof(t_coord));
	env->player_coord->pos_x = -1;
	env->player_coord->pos_y = -1;
	env->player = false;
	env->NO_image = NULL;
	env->SO_image = NULL;
	env->WE_image = NULL;
	env->EA_image = NULL;
}

int	main (int ac, char **av)
{
	t_env	env;
	if (ac < 2)
		return (arg_error(INT_TOO_FEW_ARGUMENT));
	else if (ac > 2)
		return (arg_error(INT_TOO_MANY_ARGUMENT));
	else if (check_file_format(av[1]) == false)
		return (arg_error(INT_INVALID_FILE_FORMAT));
	init_env(&env);
	if (parse(av[1], &env, false) == false)
		clean_exit(&env);
	set_map_size(&env);
	exec_init(&env);
	if (map_check(&env) == false)
		clean_exit(&env);
	ft_print_double_array(env.map, 0);
	mlx_loop(env.mlx);
	clean_exit(&env);
}
