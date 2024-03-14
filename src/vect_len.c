#include <miniRT.h>

double	vect_len(t_vect const *vect)
{
	double	tmp;

	tmp = sqrt(vect_dot(vect, vect));
	return (tmp);
}