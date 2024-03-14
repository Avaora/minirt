/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:17:37 by ikalende          #+#    #+#             */
/*   Updated: 2023/03/11 14:09:25 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	ssize_t	p;
	ssize_t	x;
	char	*ptr;

	p = 0;
	x = 0;
	while ((s1 != NULL) && (*(s1 + p) != 0x0))
		p++;
	while ((s2 != NULL) && (*(s2 + x) != 0x0))
		x++;
	ptr = ft_camalloc((p + x + 1), sizeof(char));
	if (ptr == NULL)
		return (NULL);
	*(ptr + p + x) = 0x0;
	while (x-- > 0)
		*(ptr + p + x) = *(s2 + x);
	while (p-- > 0)
		*(ptr + p) = *(s1 + p);
	return (ptr);
}

char	*ft_jonfre(char *buf, const char *tmp_buf)
{
	char	*ret;

	ret = ft_strjoin(buf, tmp_buf);
	if (buf != NULL)
		free(buf);
	return (ret);
}

int	ft_is_nwln(char *str)
{
	size_t	i;

	i = 0;
	while ((*(str + i) != 0x0) && (*(str + i) != 0x0a))
		i++;
	if (*(str + i) == 0x0a)
		return (1);
	return (0);
}

void	*ft_camalloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (count * size))
	{
		*(((char *)ptr) + i) = 0x0;
		i++;
	}
	return (ptr);
}
