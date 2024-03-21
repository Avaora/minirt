/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:05 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/21 09:53:05 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	calc_pixel_color(t_world *world)
{
	t_color	color;

	if (world->hit.is_hit == 1)
	{
		color.r = world->hit.obj->color.r;
		color.g = world->hit.obj->color.g;
		color.b = world->hit.obj->color.b;
		return (color);
	}
	color.r = 255;
	color.g = 255;
	color.b = 255;
	return (color);
}