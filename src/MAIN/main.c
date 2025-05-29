/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:15:06 by tom               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/05/29 23:14:02 by tom              ###   ########.fr       */
=======
/*   Updated: 2025/05/28 18:36:04 by bchedru          ###   ########.fr       */
>>>>>>> 130d7e4 (Bartime (#7))
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

bool	check_file_format(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".cub") != 0)
		return (false);
	return (true);
}

void	init_env(t_env *env)
{
	env->mlx = NULL;
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
<<<<<<< HEAD
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

int main(int ac, char **av)
{
	t_env env;
=======
	t_env	env;
>>>>>>> 130d7e4 (Bartime (#7))
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
<<<<<<< HEAD
	if (map_check(&env) == false)
		clean_exit(&env);
	exec_init(&env);
=======
	exec_init(&env);
	if (map_check(&env) == false)
		clean_exit(&env);
>>>>>>> 130d7e4 (Bartime (#7))
	ft_print_double_array(env.map, 0);
	mlx_loop(env.mlx);
	clean_exit(&env);
}
