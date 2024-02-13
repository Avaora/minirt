#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <unistd.h>
# include <sys/errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <libft.h>

# define BUF_SIZE 128
# define ERR_FILE "File error"

typedef struct	s_file
{
	int			fd;
	const char	*path;
	char		*scene;
}				t_file;

typedef struct	s_mem
{
	char		*scene;
}				t_mem;
void	check_path(t_file *file);
int		file_ops(t_file *file, t_mem *mem);
void	open_file(t_file *file);
void	read_to_mem(t_file *file);
void	*rezalloc(void *ptr, size_t c_size, size_t n_size);
void	set_err(const char *msg);
void	*zalloc(size_t size);


#endif