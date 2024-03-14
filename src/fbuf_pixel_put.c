/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fbuf_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:25 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/14 17:13:26 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	fbuf_pixel_put(t_window *win, int color)
{
	*(win->fbuf + (win->img_y * win->win_width) + win->img_x) = color;
}