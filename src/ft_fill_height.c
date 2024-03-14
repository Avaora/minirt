/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:00:16 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 00:00:31 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_height(t_scene *elements, char **info, int *i)
{
	double	val;

	val = ft_atof_parser(info[*i]);
	if (val == ATOF_ERR)
		return (FAILURE);
	elements->height = val;
	(*i)++;
	return (SUCCESS);
}
