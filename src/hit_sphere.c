#include <miniRT.h>

void	hit_sphere(t_world *world, t_objs *sp)
{
	t_vect	oc;
	double	a;
	double	b;
	double	c;
	double	disc;

	oc = vect_sub(&world->ray.origin, &sp->center);
	a = vect_dot(&world->ray.direction, &world->ray.direction);
	b = 2.0 * vect_dot(&world->ray.direction, &oc);
	c = vect_dot(&oc, &oc) - (sp->diameter / 2) * (sp->diameter / 2);
	disc = (b * b) - (4.0 * a * c);
	if (disc < 0.0)
		return ;
	c = (-b - sqrt(disc)) / (2.0 * a);
	if ((c <= T_MIN) || (T_MAX <= c))
		c = (-b + sqrt(disc)) / (2.0 * a);
	if ((c <= T_MIN) || (T_MAX <= c))
			return ;
	calc_nearest(world, c, sp);
}