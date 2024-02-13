#include <minirt.h>

int	file_ops(t_file *file, t_mem *mem)
{
	check_path(file);
	open_file(file);
	read_to_mem(file);
	mem->scene = file->scene;
	return (0);
}