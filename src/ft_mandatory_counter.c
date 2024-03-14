/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory_counter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bukaya <bukaya@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:21:20 by bukaya            #+#    #+#             */
/*   Updated: 2024/03/14 01:21:42 by bukaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	ft_mandatory_counter(t_list *list)
{
	t_scene		*scene;
	t_counter	*counter;
	int			err;

	counter = ft_calloc(1, sizeof(t_counter));
	err = 0;
	while (list)
	{
		scene = list->content;
		if (scene->identifier == AMBIENT)
			counter->ambient++;
		if (scene->identifier == CAMERA)
			counter->camera++;
		if (scene->identifier == LIGHT)
			counter->light++;
		list = list->next;
	}
	if (counter->ambient != 1 || counter->camera != 1 || counter->light != 1)
		err = ft_puterror("Invalid number of mandatory elements");
	free(counter);
	return (err);
}
