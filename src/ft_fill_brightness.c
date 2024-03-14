/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_brightness.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:00:52 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 00:01:09 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_brightness(t_scene *elements, char **info, int *i)
{
	double	val;

	val = ft_atof_parser(info[*i]);
	if (val == ATOF_ERR || ft_check_range(val, e_light) != 0)
		return (FAILURE);
	elements->brightness = val;
	(*i)++;
	return (SUCCESS);
}
