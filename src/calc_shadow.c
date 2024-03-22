#include <miniRT.h>

void	calc_shadow(t_world *world, double t, t_objs *obj)
{
	t_vect	tmp;
	t_vect	tmp2;

	world->hit.point = cast_ray(&world->ray, t);
	tmp = vect_sub(&world->light.center, &world->ray.origin);
	tmp2 = vect_sub(&world->hit.point, &world->ray.origin);
	if (vect_len(&tmp2) > vect_len(&tmp))
		return ;
	if (obj->id == PLANE)
		world->hit.normal = obj->direction;
	else if (obj->id == SPHERE)
	{
		world->hit.normal = vect_sub(&world->hit.point, &obj->center);
		world->hit.normal = vect_unit(&world->hit.normal);
	}
	else if (obj->id == CYLINDER)
	{
		return ;
	}
	world->hit.is_hit = 1;
	world->hit.obj = obj;
	world->hit.t = t;
}