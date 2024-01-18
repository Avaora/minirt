#include "minirt.h"
#include "mlx/mlx.h"

int	main(int argc, char *argv[])
{
	t_file	file;

	if (argc == 2)
	{
		file.path = argv[1];
		file_ops(&file);
	}
	return (0);
}