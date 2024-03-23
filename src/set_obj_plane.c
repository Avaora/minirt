/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:22 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/23 02:50:08 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_obj_plane(t_world *world, t_scene const *scene)
{
	t_objs	*obj;
	t_list	*node;

	obj = zalloc(sizeof(*obj));
	if (obj == NULL)
		set_err(NULL);
	obj->id = PLANE;
	obj->center.x = scene->coord[0];
	obj->center.y = scene->coord[1];
	obj->center.z = scene->coord[2];
	obj->direction.x = scene->vector[0];
	obj->direction.y = scene->vector[1];
	obj->direction.z = scene->vector[2];
	obj->color.r = scene->rgb[0] / 255.0;
	obj->color.g = scene->rgb[1] / 255.0;
	obj->color.b = scene->rgb[2] / 255.0;
	node = ft_lstnew(obj);
	if (node == NULL)
		set_err(NULL);
	ft_lstadd_back(&world->objs, node);
}