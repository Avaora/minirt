/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_diameter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:59:28 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 00:00:02 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_diameter(t_scene *elements, char **info, int *i)
{
	double	val;

	val = ft_atof_parser(info[*i]);
	if (val == ATOF_ERR)
		return (FAILURE);
	elements->diameter = val;
	(*i)++;
	return (SUCCESS);
}
