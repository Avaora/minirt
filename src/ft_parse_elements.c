/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 03:45:26 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 01:22:40 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_parse_elements(t_list **list, char **argv)
{
	int		fd;
	char	*line;
	bool	error_detected;

	argv++;
	error_detected = false;
	line = 0;
	if (ft_check_path(*argv) == FAILURE)
		exit (ft_puterror(FILE_EXTENSION_ERR));
	fd = open(*argv, O_RDONLY, 0644);
	if (fd == -1)
		exit (ft_puterror(FILE_ERR));
	while (ft_readline(&line, fd) && error_detected == false)
		if (ft_assign_element_values(list, line) > 0)
			error_detected = true;
	close(fd);
	if (error_detected == true || ft_mandatory_counter(*list) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
