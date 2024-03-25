/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:05 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/24 17:54:33 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	calc_pixel_color(t_world *world)
{
	t_color	diffuse;
	t_color	amb;
	t_color	color;

	if (world->hit.is_hit == 1)
	{
		amb = calc_amb_light(&world->amb_light, world->hit.obj);
		diffuse = calc_diffuse_light(&world->light, &world->hit);
		add_ray_offset(world);
		calc_shadow_ray(world);
		if (world->hit.is_hit == 1)
			return (amb);
		else
		{
			color.r = amb.r + diffuse.r;
			color.g = amb.g + diffuse.g;
			color.b = amb.b + diffuse.b;
			return (color);
		}
	}
	color.r = 1.0;
	color.g = 1.0;
	color.b = 1.0;
	return (color);
}