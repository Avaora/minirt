/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:58:50 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:59:07 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_rgb(t_scene *elements, char **info, int *i)
{
	double	val;
	int		rgb;

	rgb = 0;
	while (rgb < 3)
	{
		val = ft_atof_parser(info[*i]);
		if (val == ATOF_ERR || ft_check_range(val, e_rgb) != 0)
			return (FAILURE);
		elements->rgb[rgb] = val;
		(*i)++;
		rgb++;
	}
	return (SUCCESS);
}
