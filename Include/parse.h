/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchedru <bchedru@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:31 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/05 16:51:28 by bchedru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "Cub3d.h"

/*====================== Parse Bis ======================*/

/**
 * @brief This function take a line from the map and chack whether all char are
 * valid not.
 * 
 * @param line An line from the map.
 * @param env The environment variable.
 * @param y The location of the line.
 * @return true The line is valid.
 * @return false The line isn't valid.
 */
bool			check_map_line(char *line, t_env *env, int y);

/**
 * @brief This function check the first line of the map and verify if the map
 * start here or not.
 * 
 * @param line The line to check;
 * @param map An boolean to confirm the map strat here.
 * @return true Yes the map start here.
 * @return false No the map don't start here.
 */
bool			check_map_first_line(char *line, bool *map);

/**
 * @brief This function checks which variable the line should be assigned to.
 * 
 * @param line The line.
 * @param i The position where the line's identifier flag begins.
 * @return t_parse_flag An flag to say which flag it is;
 */
t_parse_flag	map_test(char *line, int i);

/**
 * @brief This function parse the map and store it in a structure.
 * 
 * @param depth The depth of the line.
 * @param env The environment variable.
 * @param fd The file descriptor.
 * @param line The line.
 * @return int An int depends on the result og the test on the line.
 */
int				read_map(int depth, t_env *env, int fd, char *line);

/*====================== Parse ======================*/

/**
 * @brief This function parses the map file and every variable in the correct
 * location.
 * 
 * @param file The file to read.
 * @param env The environment variable.
 * @param map An boolean to check whether the map parsing has started.
 * @return true The parsing was completed without any issues.
 * @return false The parse has failed.
 */
bool			parse(char *file, t_env *env, bool map);

/*======================== Map ========================*/

/**
 * @brief This function check Whether the map is surrounded by wall.
 * 
 * @param map The map.
 * @param x The position x of the player.
 * @param y The position y of the player.
 * @param map_size An tab with int to know the size of each line of the map.
 * @return true The map is surrounded by wall.
 * @return false The map isn't surrounded by wall.
 */
bool			floodfill(char **map, int x, int y, int *map_size);

/**
 * @brief This function launches the flood fill algorithm and restores the map
 * to its original state.
 * 
 * @param env The environment variable.
 * @return true The map is surrounded by wall.
 * @return false The map is surrounded by wall.
 */
bool			map_check(t_env *env);

/**
 * @brief Set the map size objectThis function fill the struct who contain the
 * size of each line of the map.
 * 
 * @param env The environment variable.
 */
void			set_map_size(t_env *env);

/*====================== Parse Utils ======================*/

/**
 * @brief This function verify whether the rgb is correct.
 * 
 * @param buffer The buffer with the rgb value.
 * @param flag The flag with Ceil or Floor.
 * @param env The environment variable.
 * @return true The rgb is correct.
 * @return false The rgb is not correct.
 */
bool	rgb_check(char *buffer, t_parse_flag flag, t_env *env);

char	*rgb_to_hex_char(char *buffer);
#endif