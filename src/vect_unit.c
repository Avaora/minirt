#include <miniRT.h>

t_vect	vect_unit(t_vect const *vect)
{
	t_vect	tmp;

	tmp = vect_scale(vect, 1.0 / vect_len(vect));
	return (tmp);
}