#include "minirt.h"

void	set_err(const char *msg)
{
	if (errno != 0)
		perror(msg);
	else
		printf("Error\n%s\n",msg);
	exit(1);
}