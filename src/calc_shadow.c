#include <miniRT.h>

void	calc_shadow(t_world *world, double t)
{
	t_vect	lo;
	t_vect	ho;
	t_vect	hit;

	hit = cast_ray(&world->ray, t);
	lo = vect_sub(&world->light.center, &world->ray.origin);
	ho = vect_sub(&hit, &world->ray.origin);
	if (vect_len(&ho) > vect_len(&lo))
		return ;
	world->hit.is_hit = 1;
}