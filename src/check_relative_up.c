#include <miniRT.h>

t_vect	check_relative_up(t_vect const *direction)
{
	t_vect	rel_up;
	double	cosine;

	rel_up.x = 0.0;
	rel_up.y = 1.0;
	rel_up.z = 0.0;
	cosine = vect_dot(&rel_up, direction);
	if ((cosine > 0.9) || (cosine < -0.9))
	{
		rel_up.x = 1.0;
		rel_up.y = 0.0;
		rel_up.z = 0.0;
	}
	return (rel_up);
}