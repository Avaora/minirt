/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikalende <ikalende@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:13:42 by ikalende          #+#    #+#             */
/*   Updated: 2024/03/16 00:22:27 by ikalende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	make_window(t_world *world, t_window *win)
{
	win->win_title = ft_strdup("miniRT");
	win->win_width = world->image_width;
	win->win_height = world->image_height;
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		set_err(NULL);
	win->win_ptr = mlx_new_window(win->mlx_ptr,
		win->win_width, win->win_height, win->win_title);
	if (win->win_ptr == NULL)
		set_err(NULL);
	win->img_ptr = mlx_new_image(win->mlx_ptr,
		win->win_width, win->win_height);
	if (win->img_ptr == NULL)
		set_err(NULL);
	win->fbuf = (int *)mlx_get_data_addr(win->img_ptr, &win->bpp,
		&win->bpl, &win->endian);
	win->img_x = 0;
	win->img_y = 0;
}