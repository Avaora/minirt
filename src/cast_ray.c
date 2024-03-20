#include <miniRT.h>

t_vect	cast_ray(t_ray const *ray, double t)
{
	t_vect	tmp;

	tmp = vect_scale(&ray->direction, t);
	tmp = vect_add(&ray->origin, &tmp);
	return (tmp);
}