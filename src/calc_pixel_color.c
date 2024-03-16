/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:05 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/16 07:07:39 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	calc_pixel_color(t_world *world)
{
	t_color	color;
	t_vect	unit;
	t_vect	tmp;
	t_vect	clr;
	double	a;

	unit = vect_sub(&world->vw_pixel, &world->camera.center);
	unit = vect_unit(&unit);
	a = 0.5 * (unit.y + 1.0);
	tmp.x = 1.0;
	tmp.y = 1.0;
	tmp.z = 1.0;
	tmp = vect_scale(&tmp, (1.0 - a));
	clr.x = 0.5;
	clr.y = 0.7;
	clr.z = 1.0;
	clr = vect_scale(&clr, a);
	tmp = vect_add(&tmp, &clr);
	color.r = (int)(255.999 * tmp.x);
	color.g = (int)(255.999 * tmp.y);
	color.b = (int)(255.999 * tmp.z);
	return (color);
}