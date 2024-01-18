#include "../minirt.h"

int	file_ops(t_file *file)
{
	check_file(file);
	open_file(file);
	read_to_mem(file);
	
	return (0);
}