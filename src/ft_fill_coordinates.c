/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:57:31 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:57:48 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_coordinates(t_scene *elements, char **info, int *i)
{
	double	val;
	int		coord;
	int		err;

	coord = 0;
	err = 0;
	while (coord < 3)
	{
		val = ft_atof_parser(info[*i]);
		if (val == ATOF_ERR)
			err++;
		elements->coord[coord] = val;
		(*i)++;
		coord++;
	}
	if (err)
		return (FAILURE);
	return (SUCCESS);
}
