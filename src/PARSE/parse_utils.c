/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:09:29 by tom               #+#    #+#             */
/*   Updated: 2025/05/28 15:02:51 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

char	*int_to_hex(int nb, char *base)
{
	char *res;

	res = ft_calloc(3, sizeof(char));
	if (nb < 16)
	{
		res[0] = '0';
		res[1] = base[nb];
		return (res);
	}
	res[1] = base[nb % 16];
	nb /= 16;
	res[0] = base[nb];
	return (res);
}

bool	rgb_check(char *buffer, t_parse_flag flag, t_env *env)
{
	if (flag == F)
	{
		env->F_color = rgb_to_hex_char(buffer);
		if (env->F_color == NULL)
		{
			free(buffer);
			return (parse_error(INT_WRONG_F_RGB));
		}
	}
	else if (flag == C)
	{
		env->C_color = rgb_to_hex_char(buffer);
		if (env->C_color == NULL)
		{
			free(buffer);
			return (parse_error(INT_WRONG_C_RGB));
		}
	}
	return (true);
}
