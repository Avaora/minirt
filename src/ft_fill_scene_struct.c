/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_scene_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:02:20 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 00:02:47 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_fill_scene_struct(t_scene *element, char **info, int *i, int *err)
{
	int	identifier;

	*err += ft_fill_identifier(element, info, i);
	if (ft_check_element_count(element, info) == FAILURE)
		return (ft_arrfree(info) + FAILURE);
	identifier = element->identifier;
	if (identifier == A)
		ft_fill_ambient(element, info, i);
	if (identifier != A)
		*err += ft_fill_coordinates(element, info, i);
	if (identifier == C || identifier == pl || identifier == cy)
		*err += ft_fill_vector(element, info, i);
	if (identifier == sp || identifier == cy)
		*err += ft_fill_diameter(element, info, i);
	if (identifier == L)
		*err += ft_fill_brightness(element, info, i);
	if (identifier == C)
		*err += ft_fill_fov(element, info, i);
	if (identifier == cy)
		*err += ft_fill_height(element, info, i);
	if (identifier != L && identifier != C)
		*err += ft_fill_rgb(element, info, i);
	return (*err + ft_arrfree(info));
}
