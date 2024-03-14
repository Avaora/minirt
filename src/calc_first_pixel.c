/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_first_pixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:12:57 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:12:59 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	calc_first_pixel(t_world *world)
{
	t_vect	tmp;

	tmp = vect_add(&world->delta_u, &world->delta_v);
	tmp = vect_scale(&tmp, (0.5));
	world->first_pixel = vect_add(&world->upper_left, &tmp);
}