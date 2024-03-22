/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbuf_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:25 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/22 10:48:30 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fbuf_pixel_put(t_window *win, t_color *color)
{
	int	pix_color;

	pix_color = 0;
	pix_color = color->r << 16;
	pix_color = pix_color + (color->g << 8);
	pix_color = pix_color + color->b;
	*(win->fbuf + (win->img_y * win->win_width) + win->img_x) = pix_color;
}