#include <miniRT.h>

void	calc_nearest(t_world *world, double t, t_objs const *obj)
{
	world->hit.point = cast_ray(&world->ray, t);
	if (obj->id == PLANE)
	{
		world->hit.normal = obj->direction;
	}
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