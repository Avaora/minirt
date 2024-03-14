/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_fov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:01:40 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 00:01:55 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_fov(t_scene *elements, char **info, int *i)
{
	double	val;

	val = ft_atof_parser(info[*i]);
	if (val == ATOF_ERR || ft_check_range(val, e_fov) != 0)
		return (FAILURE);
	elements->fov = val;
	(*i)++;
	return (SUCCESS);
}
