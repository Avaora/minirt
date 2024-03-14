#include <miniRT.h>

void	set_window(t_window *win, t_world *world)
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
}