#include "minirt.h"

void	open_file(t_file *file)
{
	file->fd = open(file->path, O_RDONLY);
	if (file->fd == -1)
		set_err(ERR_FILE);
}