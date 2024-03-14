/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:52 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:13:53 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	render(t_world *world, t_window *win)
{
	int	color;

	while (win->img_y < world->image_height)
	{
		win->img_x = 0;
		while (win->img_x < world->image_width)
		{
			calc_vw_pixel(world, win);
			color = calc_pixel_color();
			fbuf_pixel_put(win, color);
			win->img_x++;
		}
		win->img_y++;
	}
}