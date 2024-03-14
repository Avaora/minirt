#include <minirt.h>

void	calc_upper_left(t_world *world)
{
	t_vect	tmp;

	tmp = vect_scale(&world->camera.direction, &world->camera.focal_length);
	world->upper_left = vect_add(&world->camera.center, &tmp);
	tmp = vect_scale(&world->viewport_u, (0.5));
	world->upper_left = vect_sub(&world->upper_left, &tmp);
	tmp = vect_scale(&world->viewport_v, (0.5));
	world->upper_left = vect_sub(&world->upper_left, &tmp);
}