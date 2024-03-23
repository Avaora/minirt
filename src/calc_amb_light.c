#include <miniRT.h>

t_color	calc_amb_light(t_amb_light const *amb_l, t_objs const *obj)
{
	t_color	tmp;

	tmp.r = amb_l->color.r * obj->color.r * amb_l->power;
	tmp.g = amb_l->color.g * obj->color.g * amb_l->power;
	tmp.b = amb_l->color.b * obj->color.b * amb_l->power;
	return (tmp);
}