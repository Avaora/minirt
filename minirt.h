#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>
#include <unistd.h>
#include <sys/errno.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft/libft.h"

#define ERR_FILE "File error"

typedef struct	s_file
{
	int			fd;
	const char	*path;
	char		*scene;	
}				t_file;

void	check_file(t_file *file);
int		file_ops(t_file *file);
void	open_file(t_file *file);
void	set_err(const char *msg);
void	*zalloc(size_t size);


#endif