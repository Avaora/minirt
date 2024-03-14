/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:55:04 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/13 23:55:23 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_identifier(t_scene *element, char **info, int *i)
{
	int		err;

	err = 0;
	if (ft_safecmp("A", info[*i], ft_strlen(info[*i])) == SUCCESS)
		element->identifier = AMBIENT;
	else if (ft_safecmp("L", info[*i], ft_strlen(info[*i])) == SUCCESS)
		element->identifier = LIGHT;
	else if (ft_safecmp("C", info[*i], ft_strlen(info[*i])) == SUCCESS)
		element->identifier = CAMERA;
	else if (ft_safecmp("sp", info[*i], ft_strlen(info[*i])) == SUCCESS)
		element->identifier = SPHERE;
	else if (ft_safecmp("pl", info[*i], ft_strlen(info[*i])) == SUCCESS)
		element->identifier = PLANE;
	else if (ft_safecmp("cy", info[*i], ft_strlen(info[*i])) == SUCCESS)
		element->identifier = CYLINDER;
	else
		err = ft_puterror("Undefined identifier");
	(*i)++;
	return (err);
}
