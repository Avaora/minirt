/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:15:37 by ikalende          #+#    #+#             */
/*   Updated: 2023/03/07 06:05:52 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*tmp_buf;
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp_buf = ft_camalloc((BUFFER_SIZE + 1), sizeof(char));
	if (tmp_buf == NULL)
		return (NULL);
	buf = ft_readtil_nl(fd, buf, tmp_buf);
	if (buf == NULL)
		return (NULL);
	str = ft_ret_nl(str, buf);
	if (str == NULL)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	buf = ft_edit_buf(buf);
	return (str);
}

char	*ft_readtil_nl(int fd, char *buf, char *tmp_buf)
{
	ssize_t	read_byte;

	while (1)
	{
		read_byte = read(fd, tmp_buf, BUFFER_SIZE);
		if (read_byte < 0)
			break ;
		tmp_buf[read_byte] = 0x0;
		buf = ft_jonfre(buf, tmp_buf);
		if ((buf == NULL) || (read_byte == 0) || (ft_is_nwln(tmp_buf) == 1))
			break ;
	}
	free(tmp_buf);
	if ((read_byte < 0) && (buf != NULL))
	{
		free(buf);
		buf = NULL;
	}
	return (buf);
}

char	*ft_ret_nl(char *str, char *buf)
{
	size_t	i;

	i = 0;
	if (*buf == 0x0)
		return (NULL);
	while ((*(buf + i) != 0x0a) && (*(buf + i) != 0x0))
		i++;
	if (buf[i] == 0x0a)
		i++;
	str = ft_camalloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i] = 0x0;
	while (i > 0)
	{
		i--;
		str[i] = buf[i];
	}
	return (str);
}

char	*ft_edit_buf(char *buf)
{
	size_t	i;
	size_t	buf_size;

	buf_size = 0;
	i = 0;
	while (*(buf + buf_size) != 0x0)
		buf_size++;
	while ((*(buf + i) != 0x0a) && (*(buf + i) != 0x0))
		i++;
	if ((i < buf_size) && ((buf_size - i) != 1))
	{
		buf[0] = 0x0;
		buf = ft_jonfre(buf, (buf + i + 1));
	}
	else
	{
		free(buf);
		buf = NULL;
	}
	return (buf);
}
