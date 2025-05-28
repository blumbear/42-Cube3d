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

# define STR_TOO_FEW_ARGUMENT "Too few argument.\nUsage: ./Cube3d <test>.cub\n"
# define STR_TOO_MANY_ARGUMENT "Too many argument.\nUsage: ./Cube3d <test>.cub\n"
# define STR_INVALID_FILE_FORMAT "Invalid file format.\nThe file format must be \".cub\"\n"
# define STR_INVALID_FILE "The File don't exist or can't be open.\n"
# define STR_MAP_INVALID_PARAM "The file contains an invalid parameter.\n"
# define STR_MAP_INVALID_CHAR "The map contains an invalid character.\n"
# define STR_DOUBLE_PLAYER_IN_MAP "The map contain two or more players.\n"
# define STR_MAP_IS_NOT_SURROUNDED "The area around the player is not fully enclosed by walls.\n"
# define STR_WRONG_F_RGB "The RGB code of the floor is not correct.\n"
# define STR_WRONG_C_RGB "The RGB code of the ceil is not correct.\n"

# define PARSE_ERROR_MSG "PARSE_ERROR: "
# define ARGUMENT_ERROR_MSG "ARGUMENTS_ERROR: "

int		arg_error(int error_flag);
bool	parse_error(int error_flag);

# endif