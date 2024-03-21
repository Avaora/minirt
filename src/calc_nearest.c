#include <miniRT.h>

void	calc_nearest(t_world *world, double t, t_objs const *obj)
{
	if (t >= world->hit.t)
		return ;
	world->hit.is_hit = 1;
	world->hit.obj = obj;
	if (obj->id == PLANE)
	{
		world->hit.point = cast_ray(&world->ray, t);
		world->hit.normal = obj->direction;
		if (vect_dot(&obj->direction, &world->ray.direction) > 0)
			world->hit.normal = vect_scale(&obj->direction, -1.0);
		world->hit.t = t;
	}
	else if (obj->id == SPHERE)
	{
		world->hit.point = cast_ray(&world->ray, t);
		world->hit.normal = vect_sub(&world->hit.point, &obj->center);
		world->hit.normal = vect_scale(&world->hit.normal, (1 / (obj->diameter/2)));
		world->hit.t = t;
	}
	else if (obj->id == CYLINDER)
	{
		return ;
	}
}