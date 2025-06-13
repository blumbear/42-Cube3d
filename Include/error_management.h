/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:15 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/13 15:38:10 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# define TEST_PRINT "HERE\n"

# define INT_TOO_FEW_ARGUMENT 1
# define INT_TOO_MANY_ARGUMENT 2
# define INT_INVLD_FORMAT 3
# define INT_INVALID_FILE 4
# define INT_MAP_INVALID_PARAM 5
# define INT_MAP_INVALID_CHAR 6
# define INT_DOUBLE_PLAYER_IN_MAP 7
# define INT_NT_SURND 8
# define INT_WRONG_F_RGB 9
# define INT_WRONG_C_RGB 10
# define INT_C_COLOR_N_DEF 11
# define INT_F_COLOR_N_DEF 12
# define INT_IMAGE_NOT_FOUND 13
# define INT_MISSING_PLAYER 14

# define TOO_FEW_ARGUMENT "Too few argument.\nUsage: ./Cub3d <test>.cub\n"
# define TOO_MANY_ARGUMENT "Too many argument.\nUsage: ./Cub3d <test>.cub\n"
# define INVLD_FORMAT "Invalid file format.\nThe file format must be \".cub\"\n"
# define INVALID_FILE "The File don't exist or can't be open.\n"
# define MAP_INVALID_PARAM "The file contains an invalid parameter.\n"
# define MAP_INVALID_CHAR "The map contains an invalid character.\n"
# define DOUBLE_PLAYER_IN_MAP "The map contain two or more players.\n"
# define NT_SURND "The area around the player is not fully enclosed by walls.\n"
# define WRONG_F_RGB "The RGB code of the floor is not correct.\n"
# define WRONG_C_RGB "The RGB code of the ceil is not correct.\n"
# define C_COLOR_N_DEF "The file does not contain any rgb code for the ceil.\n"
# define F_COLOR_N_DEF "The file does not contain any rgb code for the floor.\n"
# define IMAGE_NOT_FOUND "One of the walls' image could not be found.\n"
# define MISSING_PLAYER "The map has to contain one player.\n"

# define PARSE_ERROR_MSG "PARSE_ERROR: "
# define ARGUMENT_ERROR_MSG "ARGUMENTS_ERROR: "

int		arg_error(int error_flag);
bool	parse_error(int error_flag);
int		end_prog(t_env *env);
void	clean_exit(t_env *env);

#endif