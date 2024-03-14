/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_element_count.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:55:49 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:56:04 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_check_element_count(t_scene *elements, char **info)
{
	int	err;

	err = 0;
	if (elements->identifier == AMBIENT && ft_arrlen(info) != 5)
		err = ft_puterror("Invalid number of elements for AMBIENT");
	else if (elements->identifier == CAMERA && ft_arrlen(info) != 8)
		err = ft_puterror("Invalid number of elements for CAMERA");
	else if (elements->identifier == LIGHT && ft_arrlen(info) != 8)
		err = ft_puterror("Invalid number of elements for LIGHT");
	else if (elements->identifier == SPHERE && ft_arrlen(info) != 8)
		err = ft_puterror("Invalid number of elements for SPHERE");
	else if (elements->identifier == PLANE && ft_arrlen(info) != 10)
		err = ft_puterror("Invalid number of elements for PLANE");
	else if (elements->identifier == CYLINDER && ft_arrlen(info) != 12)
		err = ft_puterror("Invalid number of elements for CYLINDER");
	return (err);
}
