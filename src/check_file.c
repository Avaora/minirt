#include "../minirt.h"

void	check_file(t_file *file)
{
	if ((file->path == NULL) || (ft_strlen(file->path) == 0))
		set_err(ERR_FILE);
}