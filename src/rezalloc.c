#include <minirt.h>

void	*rezalloc(void *ptr, size_t c_size, size_t n_size)
{
	char	*buf;

	if (ptr == NULL)
		return (zalloc(n_size));
	else if (n_size == 0)
	{
		free(ptr);
		return (zalloc(n_size));
	}
	buf = zalloc(n_size);
	if (buf == NULL)
		return (NULL);
	if (c_size >= n_size)
		ft_memmove(buf, ptr, n_size);
	else
		ft_memmove(buf, ptr, c_size);
	free(ptr);
	return (buf);
}