/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_upper_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:14 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/24 06:33:37 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	calc_upper_left(t_world *world)
{
	t_vect	tmp;

	tmp = vect_scale(&world->camera.w, -world->camera.focal_length);
	world->upper_left = vect_add(&world->camera.center, &tmp);
	tmp = vect_scale(&world->viewport_u, (0.5));
	world->upper_left = vect_sub(&world->upper_left, &tmp);
	tmp = vect_scale(&world->viewport_v, (0.5));
	world->upper_left = vect_sub(&world->upper_left, &tmp);
}