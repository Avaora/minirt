#include <miniRT.h>

double	hit_plane(t_ray const *ray, t_objs const *pl)
{
	double	res;
	double	div;
	t_vect	oc;
	
	div = vect_dot(&pl->direction, &ray->direction);
	oc = vect_sub(&pl->center, &ray->origin);
	res = vect_dot(&pl->direction, &oc);
	if (div == 0)
	{
		if (res == 0)
			return (vect_len(&ray->direction));
		else
			return (T_ERR);
	}
	else
	{
		res = res / div;
		if ((res <= T_MIN) || (T_MAX <= res))
			return (T_ERR);
		else
			return (res);
	}
}