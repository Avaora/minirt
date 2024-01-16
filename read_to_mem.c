#include "minirt.h"

void	read_to_mem(t_file *file)
{
	char	*tmp_buf;
	size_t	trd_byte;
	int		rd_byte;

	trd_byte = 0;
	tmp_buf = zalloc(BUF_SIZE);
	if (tmp_buf == NULL)
		set_err(NULL);
	while (1)
	{
		rd_byte = read(file->fd, tmp_buf + trd_byte, BUF_SIZE);
		if (rd_byte != BUF_SIZE)
			break ;
		trd_byte += rd_byte;
		tmp_buf = rezalloc(tmp_buf, trd_byte, trd_byte + BUF_SIZE);
		if (tmp_buf == NULL)
			set_err(NULL);
	}
	if (rd_byte == -1)
		set_err(NULL);
	tmp_buf = rezalloc(tmp_buf, trd_byte + rd_byte, trd_byte + rd_byte);
	if (tmp_buf == NULL)
		set_err(NULL);
	file->scene = tmp_buf;
}