#include <miniRT.h>

t_vect	vect_cross(t_vect const *vect1, t_vect const *vect2)
{
	t_vect	tmp;

	tmp.x = (vect1->y * vect2->z) - (vect1->z * vect2->y);
	tmp.y = (vect1->z * vect2->x) - (vect1->x * vect2->z);
	tmp.z = (vect1->x * vect2->y) - (vect1->y * vect2->x);
	return (tmp);
}