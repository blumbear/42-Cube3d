/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 02:25:15 by bchedru           #+#    #+#             */
/*   Updated: 2025/06/11 14:30:26 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# define TEST_PRINT "HERE\n"

# define INT_TOO_FEW_ARGUMENT 1
# define INT_TOO_MANY_ARGUMENT 2
# define INT_INVALID_FILE_FORMAT 3
# define INT_INVALID_FILE 4
# define INT_MAP_INVALID_PARAM 5
# define INT_MAP_INVALID_CHAR 6
# define INT_DOUBLE_PLAYER_IN_MAP 7
# define INT_MAP_IS_NOT_SURROUNDED 8
# define INT_WRONG_F_RGB 9
# define INT_WRONG_C_RGB 10
# define INT_C_COLOR_NOT_DEFINE 11
# define INT_F_COLOR_NOT_DEFINE 12

# define STR_TOO_FEW_ARGUMENT "Too few argument.\nUsage: ./Cub3d <test>.cub\n"
# define STR_TOO_MANY_ARGUMENT "Too many argument.\nUsage: ./Cub3d <test>.cub\n"
# define STR_INVALID_FILE_FORMAT "Invalid file format.\nThe file format must be \".cub\"\n"
# define STR_INVALID_FILE "The File don't exist or can't be open.\n"
# define STR_MAP_INVALID_PARAM "The file contains an invalid parameter.\n"
# define STR_MAP_INVALID_CHAR "The map contains an invalid character.\n"
# define STR_DOUBLE_PLAYER_IN_MAP "The map contain two or more players.\n"
# define STR_MAP_IS_NOT_SURROUNDED "The area around the player is not fully enclosed by walls.\n"
# define STR_WRONG_F_RGB "The RGB code of the floor is not correct.\n"
# define STR_WRONG_C_RGB "The RGB code of the ceil is not correct.\n"
# define STR_C_COLOR_NOT_DEFINE "The file does not contain any rgb code for the ceil.\n"
# define STR_F_COLOR_NOT_DEFINE "The file does not contain any rgb code for the floor.\n"

# define PARSE_ERROR_MSG "PARSE_ERROR: "
# define ARGUMENT_ERROR_MSG "ARGUMENTS_ERROR: "

int		arg_error(int error_flag);
bool	parse_error(int error_flag);
int		end_prog(t_env *env);
void	clean_exit(t_env *env);

#endif