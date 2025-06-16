/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:27:50 by tom               #+#    #+#             */
/*   Updated: 2025/06/16 19:48:43 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

t_limits	calculate_limits(int wall_height)
{
	t_limits	limits;

	limits.beginning = -wall_height / 2 + HEIGHT / 2;
	if (limits.beginning < 0)
		limits.beginning = 0;
	limits.end = wall_height / 2 + HEIGHT / 2;
	if (limits.end >= HEIGHT)
		limits.end = HEIGHT - 1;
	return (limits);
}

void	player_init_north(t_coord *coords, int i, int j)
{
	coords->pos_x = i + 0.5;
	coords->pos_y = j + 0.5;
	coords->dir_x = 0;
	coords->dir_y = -1;
	coords->plane_x = 0.66;
	coords->plane_y = 0;
}

void	player_init_south(t_coord *coords, int i, int j)
{
	coords->pos_x = i + 0.5;
	coords->pos_y = j + 0.5;
	coords->dir_x = 0;
	coords->dir_y = 1;
	coords->plane_x = -0.66;
	coords->plane_y = 0;
}

void	player_init_east(t_coord *coords, int i, int j)
{
	coords->pos_x = i + 0.5;
	coords->pos_y = j + 0.5;
	coords->dir_x = 1;
	coords->dir_y = 0;
	coords->plane_x = 0;
	coords->plane_y = 0.66;
}

void	player_init_west(t_coord *coords, int i, int j)
{
	coords->pos_x = i + 0.5;
	coords->pos_y = j + 0.5;
	coords->dir_x = -1;
	coords->dir_y = 0;
	coords->plane_x = 0;
	coords->plane_y = -0.66;
}
