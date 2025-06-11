/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:09:29 by tom               #+#    #+#             */
/*   Updated: 2025/06/11 15:28:28 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

uint32_t	rgb_to_uint_32(char *buffer)
{
	int			i;
	char		**tmp_split;
	uint32_t	rgba;

	i = -1;
	while (buffer[++i])
		if (!ft_isdigit(buffer[i]) && buffer[i] != ',')
			return (0);
	rgba = 0;
	tmp_split = ft_split(buffer, ',');
	rgba |= (uint32_t)ft_atoi(tmp_split[0]) << 24;
	rgba |= (uint32_t)ft_atoi(tmp_split[1]) << 16;
	rgba |= (uint32_t)ft_atoi(tmp_split[2]) << 8;
	rgba |= (uint32_t)255;
	return (rgba);
}

bool	rgb_check(char *buffer, t_parse_flag flag, t_env *env)
{
	if (flag == F)
	{
		env->f_color = rgb_to_uint_32(buffer);
		if (env->f_color == 0)
		{
			free(buffer);
			return (parse_error(INT_WRONG_F_RGB));
		}
	}
	else if (flag == C)
	{
		env->c_color = rgb_to_uint_32(buffer);
		if (env->c_color == 0)
		{
			free(buffer);
			return (parse_error(INT_WRONG_C_RGB));
		}
	}
	return (true);
}
