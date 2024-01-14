#include "minirt.h"

void	*zalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}