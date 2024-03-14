/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:38:41 by bukaya            #+#    #+#             */
/*   Updated: 2024/02/27 04:45:48 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_readline(char **line, int fd)
{
	while (true)
	{
		*line = get_next_line(fd);
		if (*line && ft_safecmp(*line, "\n", ft_strlen(*line)) == 0)
			free(*line);
		else if (*line != 0)
			return (1);
		else
			return (0);
	}
}
