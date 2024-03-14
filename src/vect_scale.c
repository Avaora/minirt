#include <minirt.h>

t_vect	vect_scale(t_vect const *vect, double scalar)
{
	t_vect	tmp;

	tmp.x = vect->x * scalar;
	tmp.y = vect->y * scalar;
	tmp.z = vect->z * scalar;
	return (tmp);
}