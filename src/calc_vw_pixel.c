#include <miniRT.h>

void	calc_vw_pixel(t_world *world, t_window *win)
{
	t_vect	tmp;

	tmp = vect_scale(&world->delta_u, win->img_x);
	world->vw_pixel = vect_add(&world->first_pixel, &tmp);
	tmp = vect_scale(&world->delta_v, win->img_y);
	world->vw_pixel = vect_add(&world->vw_pixel, &tmp);
}