#include <miniRT.h>

double	get_near(t_ray const *ray, double t1, double t2)
{
	t_ray	r1;
	t_ray	r2;
	double	res1;
	double	res2;

	r1.origin = ray->origin;
	r1.direction = ray->direction;
	r2.origin = ray->origin;
	r2.direction = ray->direction;
	r1.direction = vect_scale(&r1.direction, t1);
	r2.direction = vect_scale(&r2.direction, t2);
	res1 = vect_len(&r1.direction);
	res2 = vect_len(&r2.direction);
	if (res1 > res2)
		return (res2);
	return (res1);
}