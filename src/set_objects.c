/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:43 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/16 03:52:55 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_objects(t_world *world, t_list const *scene)
{
	t_scene	*obj;

	world->objs = NULL;
	while (scene != NULL)
	{
		obj = scene->content;
		if (obj->identifier == AMBIENT)
			set_ambient(world, obj);
		else if (obj->identifier == CAMERA)
			set_camera(world, obj);
		else if (obj->identifier == LIGHT)
			set_light(world, obj);
		else if (obj->identifier == PLANE)
			set_obj_plane(world, obj);
		else if (obj->identifier == SPHERE)
			set_obj_sphere(world, obj);
		else if (obj->identifier == CYLINDER)
			set_obj_cylinder(world, obj);
		scene = scene->next;
	}
}