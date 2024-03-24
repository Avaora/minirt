#include <miniRT.h>

void	add_ray_offset(t_world *world)
{
	t_vect	tmp;

	tmp = vect_scale(&world->hit.normal, 0.0000001); // calc that constant based on objects dimension
	world->ray.origin = vect_add(&world->hit.point, &tmp);
	tmp = vect_sub(&world->light.center, &world->ray.origin);
	world->ray.direction = vect_unit(&tmp);
}