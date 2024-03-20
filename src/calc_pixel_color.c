/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pixel_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:05 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/20 15:46:49 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	calc_pixel_color(t_world *world)
{
	t_color	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (world->hit.is_hit == 1)
	{
		color.r = 0;
		color.g = 0;
		color.b = 0;
		return (color);
	}
	color.r = 255;
	color.g = 255;
	color.b = 255;
	return (color);
}