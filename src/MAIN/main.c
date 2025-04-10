/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:15:06 by tom               #+#    #+#             */
/*   Updated: 2025/04/10 17:54:27 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3d.h"

bool check_file_format(char *file_name)
{
	if (ft_strcmp(file_name + ft_strlen(file_name) - 4, ".cub") != 0)
		return (false);
	return (true);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (arg_error(TOO_FEW_ARGUMENT));
	else if (ac > 2)
		return (arg_error(TOO_MANY_ARGUMENT));
	else if (check_file_format(av[1]) == false)
		return (arg_error(INVALID_FILE_FORMAT));
	else 
	return (EXIT_SUCCESS);
}
