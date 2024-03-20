/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:26 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/20 04:25:56 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_obj_sphere(t_world *world, t_scene const *scene)
{
	t_objs		*obj;
	t_list		*node;

	obj = zalloc(sizeof(*obj));
	if (obj == NULL)
		set_err(NULL);
	obj->id = SPHERE;
	obj->center.x = scene->coord[0];
	obj->center.y = scene->coord[1];
	obj->center.z = scene->coord[2];
	obj->diameter = scene->diameter;
	obj->color.r = scene->rgb[0];
	obj->color.g = scene->rgb[1];
	obj->color.b = scene->rgb[2];
	node = ft_lstnew(obj);
	if (node == NULL)
		set_err(NULL);
	ft_lstadd_back(&world->objs, node);
}