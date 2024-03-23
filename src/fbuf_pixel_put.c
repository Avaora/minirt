/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbuf_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:25 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/23 02:54:47 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fbuf_pixel_put(t_window *win, t_color *color)
{
	int	pix_color;

	if (color->r > 1.0)
		color->r = 1.0;
	if (color->g > 1.0)
		color->g = 1.0;
	if (color->b > 1.0)
		color->b = 1.0;
	pix_color = 0;
	pix_color = (int)(255.999 * color->r) << 16;
	pix_color += (int)(255.999 * color->g) << 8;
	pix_color += (int)(255.999 * color->b);
	*(win->fbuf + (win->img_y * win->win_width) + win->img_x) = pix_color;
}