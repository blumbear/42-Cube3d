/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:09:29 by tom               #+#    #+#             */
/*   Updated: 2025/06/12 15:22:33 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

bool	rgb_split_check(char **split)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!split[i])
			return (false);
		i++;
	}
	return (true);
}

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
	if (!rgb_split_check(tmp_split))
	{
		ft_free_double_array(tmp_split);
		return (0);
	}
	rgba |= (uint32_t)ft_atoi(tmp_split[0]) << 24;
	rgba |= (uint32_t)ft_atoi(tmp_split[1]) << 16;
	rgba |= (uint32_t)ft_atoi(tmp_split[2]) << 8;
	rgba |= (uint32_t)255;
	ft_free_double_array(tmp_split);
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
