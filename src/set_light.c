/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:13 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/23 19:29:19 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_light(t_world *world, t_scene const *scene)
{
	world->light.id = LIGHT;
	world->light.center.x = scene->coord[0];
	world->light.center.y = scene->coord[1];
	world->light.center.z = scene->coord[2];
	world->light.power = scene->brightness;
	world->light.color.r = 1;
	world->light.color.g = 1;
	world->light.color.b = 1;
}