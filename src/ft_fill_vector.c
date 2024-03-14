/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:58:10 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:58:29 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_vector(t_scene *elements, char **info, int *i)
{
	double	val;
	int		xyz;
	int		err;

	xyz = 0;
	err = 0;
	while (xyz < 3)
	{
		val = ft_atof_parser(info[*i]);
		if (val == ATOF_ERR || ft_check_range(val, e_vector) != 0)
			err++;
		elements->vector[xyz] = val;
		(*i)++;
		xyz++;
	}
	if (err)
		return (FAILURE);
	return (SUCCESS);
}
