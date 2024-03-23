#include <miniRT.h>

double	hit_sphere(t_ray const *ray, t_objs const *sp)
{
	t_vect	oc;
	double	a;
	double	b;
	double	c;
	double	disc;

	oc = vect_sub(&ray->origin, &sp->center);
	a = vect_dot(&ray->direction, &ray->direction);
	b = 2.0 * vect_dot(&ray->direction, &oc);
	c = vect_dot(&oc, &oc) - (sp->diameter / 2) * (sp->diameter / 2);
	disc = (b * b) - (4.0 * a * c);
	if (disc < 0.0)
		return (T_ERR);
	c = (-b - sqrt(disc)) / (2.0 * a);
	if ((c <= T_MIN) || (T_MAX <= c))
		c = (-b + sqrt(disc)) / (2.0 * a);
	if ((c <= T_MIN) || (T_MAX <= c))
			return (T_ERR);
	return (c);
}