/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:48 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/16 08:48:35 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	make_world(t_world *world, t_list const *scene)
{
	set_objects(world, scene);
	world->image_width = IMG_WIDTH;
	if (world->image_width < 128)
		world->image_width = 128;
	world->image_height = IMG_HEIGHT;
	if (world->image_height < 128)
		world->image_height = 128;
	world->viewport_height = VIEWPORT_HEIGHT;
	if (world->viewport_height < 1)
		world->viewport_height = 1.0;
	world->viewport_width = world->viewport_height
		* ((double)world->image_width / world->image_height);
	world->viewport_u.x = world->viewport_width;
	world->viewport_u.y = 0;
	world->viewport_u.z = 0;
	world->viewport_v.x = 0;
	world->viewport_v.y = world->viewport_height * -1.0;
	world->viewport_v.z = 0;
	world->delta_u = vect_scale(&world->viewport_u,
				((double)1 / world->image_width));
	world->delta_v = vect_scale(&world->viewport_v,
				((double)1 / world->image_height));
	world->camera.focal_length = (vect_len(&world->viewport_u) / 2)
		/ tan((world->camera.field_of_view / 2) * (M_PI / 180));
	calc_upper_left(world);
	calc_first_pixel(world);
}