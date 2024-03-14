#include <miniRT.h>

void	fbuf_pixel_put(t_window *win, int color)
{
	*(win->fbuf + (win->img_y * win->win_width) + win->img_x) = color;
}