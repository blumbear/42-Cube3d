/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:15:46 by bchedru           #+#    #+#             */
/*   Updated: 2024/06/28 02:37:47 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libamoa.h"

void	ft_print_double_array(char **double_array, bool	new_line)
{
	int	i;

	i = -1;
	if (new_line)
		while (double_array[++i])
			ft_printf("%s\n", double_array[i]);
	else
		while (double_array[++i])
			ft_printf("%s", double_array[i]);
}
