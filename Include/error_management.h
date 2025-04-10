#ifndef ERROR_MANAGEMENT_H
# define ERROR_MANAGEMENT_H

# define TOO_FEW_ARGUMENT 1
# define TOO_MANY_ARGUMENT 2
# define INVALID_FILE_FORMAT 3
# define INVALID_FILE 4

int	arg_error(int error_flag);

# endif