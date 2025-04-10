#include "Cube3d.h"

bool parse(char *file, t_env *env)
{
	int temp;

	(void)env;
	temp = open(file, O_RDONLY);
	if (temp == -1)
		return (false);
	close(temp);
	return (true);
}
