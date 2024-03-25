/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_vw_pixel_and_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:19 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/25 02:03:15 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	calc_vw_pixel_and_ray(t_world *world, t_window *win)
{
	t_vect	tmp;

	tmp = vect_scale(&world->delta_u, win->img_x);
	world->vw_pixel = vect_add(&world->first_pixel, &tmp);
	tmp = vect_scale(&world->delta_v, win->img_y);
	world->vw_pixel = vect_add(&world->vw_pixel, &tmp);
	world->ray.origin = world->camera.center;
	tmp = vect_sub(&world->vw_pixel, &world->camera.center);
	world->ray.direction = vect_unit(&tmp);
}