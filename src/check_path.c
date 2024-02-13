#include <minirt.h>

void	check_path(t_file *file)
{
	size_t	len;

	if (file->path == NULL)
		set_err(ERR_FILE);
	len = ft_strlen(file->path);
	if (len == 0)
		set_err(ERR_FILE);
}