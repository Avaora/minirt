/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:48 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/24 05:23:16 by ikalende         ###   ########.fr       */
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
	set_vw_vectors(world);
	calc_upper_left(world);
	calc_first_pixel(world);
}