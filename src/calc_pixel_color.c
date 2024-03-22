/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:05 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/22 13:10:30 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	calc_pixel_color(t_world *world)
{
	t_color	color;
	t_hit	intsec;

	intsec = world->hit;
	(void)intsec;
	if (world->hit.is_hit == 1)
	{
		world->ray.origin = vect_scale(&world->hit.normal, 0.0001);
		world->ray.origin = vect_add(&world->hit.point, &world->ray.origin);
		world->ray.direction = vect_sub(&world->light.center, &world->ray.origin);
		world->ray.direction = vect_unit(&world->ray.direction);
		calc_shadow_ray(world);	
		if (world->hit.is_hit == 0)
		{
			color.r = world->hit.obj->color.r;
			color.g = world->hit.obj->color.g;
			color.b = world->hit.obj->color.b;
			return (color);
		}
		else
		{
			color.r = 0;
			color.g = 0;
			color.b = 0;
			return (color);
		}
	}
	color.r = 255;
	color.g = 255;
	color.b = 255;
	return (color);
}