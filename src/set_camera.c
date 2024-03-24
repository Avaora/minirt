/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:04 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/24 05:03:21 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_camera(t_world *world, t_scene const *scene)
{
	world->camera.id = CAMERA;
	world->camera.center.x = scene->coord[0];
	world->camera.center.y = scene->coord[1];
	world->camera.center.z = scene->coord[2];
	world->camera.direction.x = scene->vector[0];
	world->camera.direction.y = scene->vector[1];
	world->camera.direction.z = scene->vector[2];
	world->camera.field_of_view = scene->fov;
	world->camera.focal_length = 1.0;
	world->camera.relative_up = check_relative_up(&world->camera.direction);
}