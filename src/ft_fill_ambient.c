/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:56:38 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:57:08 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_ambient(t_scene *elements, char **info, int *i)
{
	double	val;

	val = ft_atof_parser(info[*i]);
	if (val == ATOF_ERR || ft_check_range(val, e_light) != 0)
		return (FAILURE);
	elements->amb_light = val;
	(*i)++;
	return (SUCCESS);
}
