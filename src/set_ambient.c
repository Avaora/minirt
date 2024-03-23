/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:14:00 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/23 02:49:27 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_ambient(t_world *world, t_scene const *scene)
{
	world->amb_light.id = AMBIENT;
	world->amb_light.power = scene->amb_light;
	world->amb_light.color.r = scene->rgb[0] / 255.0;
	world->amb_light.color.g = scene->rgb[1] / 255.0;
	world->amb_light.color.b = scene->rgb[2] / 255.0;
}