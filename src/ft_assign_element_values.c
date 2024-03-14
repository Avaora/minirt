/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_element_values.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 04:46:20 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 00:03:09 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_assign_element_values(t_list **list, char *line)
{
	t_scene	*scene_elements;
	char	**element_info;
	int		index;
	int		err;

	index = 0;
	err = 0;
	element_info = ft_split_set(line, SPLIT_SET);
	scene_elements = ft_calloc(sizeof(t_scene), 1);
	ft_lstadd_back(list, ft_lstnew(scene_elements));
	free(line);
	return (ft_fill_scene_struct(scene_elements, element_info, &index, &err));
}
