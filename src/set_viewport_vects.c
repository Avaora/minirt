/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_viewport_vects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:15:11 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:15:12 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	set_viewport_vects(t_world *world)
{
	world->viewport_u.x = world->viewport_width;
	world->viewport_u.y = 0;
	world->viewport_u.z = 0;
	world->viewport_v.x = 0;
	world->viewport_v.y = world->viewport_height * -1;
	world->viewport_v.z = 0;
	world->delta_u = vect_scale(&world->viewport_u,
				((double)1 / world->image_width));
	world->delta_v = vect_scale(&world->viewport_v,
				((double)1 / world->image_height));
}