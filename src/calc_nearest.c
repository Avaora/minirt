#include <miniRT.h>

void	calc_nearest(t_world *world, t_objs const *obj, double t)
{
	t_vect	tmp;
	t_vect	tmp2;
	double	res;

	world->hit.point = cast_ray(&world->ray, t);
	if (obj->id == PLANE)
		world->hit.normal = obj->direction;
	else if (obj->id == SPHERE)
	{
		world->hit.normal = vect_sub(&world->hit.point, &obj->center);
		world->hit.normal = vect_scale(&world->hit.normal, 1.0 / (obj->diameter / 2));
	}
	else if (obj->id == CYLINDER)
	{
		tmp = vect_sub(&world->hit.point, &obj->center);
		res = vect_dot(&tmp, &obj->direction);
		tmp2 = vect_scale(&obj->direction, res);
		tmp = vect_sub(&tmp, &tmp2);
		world->hit.normal = vect_unit(&tmp);
	}
	world->hit.is_hit = 1;
	world->hit.obj = obj;
	world->hit.t = t;
}