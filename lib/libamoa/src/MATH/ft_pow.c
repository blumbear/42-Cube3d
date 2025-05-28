#include "libamoa.h"

int	ft_pow(int n, int pow)
{
	int res;

	if (pow < 0)
		return (0);
	res = 1;
	while (pow-- > 0)
		res *= n;
	return (res);
}
