#include <miniRT.h>

void	hit_plane(t_world *world, t_objs *pl)
{
	double	res;
	double	div;
	t_vect	oc;
	
	div = vect_dot(&pl->direction, &world->ray.direction);
	if (div == 0)
	{
		oc = vect_sub(&pl->center, &world->ray.origin);
		if (vect_dot(&pl->direction, &oc) == 0)
		{
			res = vect_len(&world->ray.direction);
			calc_nearest(world, res, pl);
		}
	}
	else
	{
		oc = vect_sub(&pl->center, &world->ray.origin);
		res = vect_dot(&pl->direction, &oc);
		res = res / div;
		if ((res <= T_MIN) || (T_MAX <= res))
			return ;
		if (res < 0)
			return ;
		calc_nearest(world, res, pl);
	}
}