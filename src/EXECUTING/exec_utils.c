/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:09 by tom               #+#    #+#             */
/*   Updated: 2025/05/29 23:36:32 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	get_largest_map_column(t_env *env)
{
	int	i;

	i = 0;
	while (env->map_size[i])
		i++;
	return (i);
}
