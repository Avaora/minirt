#include <miniRT.h>

t_color	calc_diffuse_light(t_light const *light, t_hit const *hit)
{
	t_color	tmp;
	t_vect	dir;
	double	pwr;

	dir = vect_sub(&light->center, &hit->point);
	dir = vect_unit(&dir);
	pwr = vect_dot(&dir, &hit->normal);
	tmp.r = pwr * light->color.r * hit->obj->color.r;
	tmp.g = pwr * light->color.g * hit->obj->color.g;
	tmp.b = pwr * light->color.b * hit->obj->color.b;
	return (tmp);
}