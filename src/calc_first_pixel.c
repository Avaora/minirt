#include <miniRT.h>

void	calc_first_pixel(t_world *world)
{
	t_vect	tmp;

	tmp = vect_add(&world->delta_u, &world->delta_v);
	tmp = vect_scale(&tmp, (0.5));
	world->first_pixel = vect_add(&world->upper_left, &tmp);
}