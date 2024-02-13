#include <minirt.h>
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_file	file;
	t_mem	mem;

	if (argc == 2)
	{
		file.path = argv[1];
		file_ops(&file, &mem);
		mem_ops(&mem);
	}
	return (0);
}
