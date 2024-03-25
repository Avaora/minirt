#include <miniRT.h>

static void	calc_cylinder_coef(double (*coef)[3], t_ray const *ray, t_objs const *cy)
{
	t_vect	da;
	t_vect	oa;
	t_vect	oc;
	double	scalar;

	oc = vect_sub(&ray->origin, &cy->center);
	scalar = vect_dot(&ray->direction, &cy->direction);
	da = vect_scale(&cy->direction, scalar);
	da = vect_sub(&ray->direction, &da);
	scalar = vect_dot(&oc, &cy->direction);
	oa = vect_scale(&cy->direction, scalar); 
	oa = vect_sub(&oc, &oa);
	(*coef)[0] = vect_dot(&da, &da);
	(*coef)[1] = 2.0 * vect_dot(&da, &oa);
	(*coef)[2] = vect_dot(&oa, &oa) - (cy->diameter / 2) * (cy->diameter / 2);
}

static double	check_top_cap(t_ray const *ray, t_objs const *cy)
{
	double	top_t;
	double	d;
	t_vect	t;
	t_vect	tc_center;
	t_vect	tmp;
	
	tmp = vect_scale(&cy->direction, cy->height);
	tc_center = vect_add(&cy->center, &tmp);
	top_t = vect_dot(&tc_center, &cy->direction);
	d = vect_dot(&ray->origin, &cy->direction);
	top_t = top_t - d;
	top_t = top_t / vect_dot(&ray->direction, &cy->direction);  
	t = cast_ray(ray, top_t);
	tmp = vect_sub(&t, &tc_center);
	if (vect_len(&tmp) <= (cy->diameter / 2))
		return top_t;
	return (T_ERR);
}

static double	check_bot_cap(t_ray const *ray, t_objs const *cy)
{
	t_vect	bc_center;
	t_vect	bot_intersect;
	t_vect	tmp;
	double	bot_t;
	double	d;
	
	bc_center = vect_scale(&cy->center, -1.0);
	bot_t = vect_dot(&bc_center, &cy->direction);
	d = vect_dot(&ray->origin, &cy->direction);
	bot_t = bot_t - d;
	bot_t = bot_t / vect_dot(&ray->direction, &cy->direction);
	bot_intersect = cast_ray(ray, bot_t);
	tmp = vect_sub(&bot_intersect, &bc_center);
	if (vect_len(&tmp) <= (cy->diameter / 2))
		return bot_t;
	return (T_ERR);
}

double	hit_cylinder(t_ray const *ray, t_objs const *cy)
{
	t_vect	tmp;
	double	coef[3];
	double	disc;
	double	t;

	calc_cylinder_coef(&coef, ray, cy);
	disc = check_top_cap(ray, cy);
	if (disc < T_MAX)
		return (disc);
	disc = check_bot_cap(ray, cy);
	if (disc < T_MAX)
		return (disc);
	disc = (coef[1] * coef[1]) - (4.0 * coef[0] * coef[2]);
	if (disc < 0.0)
		return (T_ERR);
	t = (-coef[1] - sqrt(disc)) / (2.0 * coef[0]);
	if ((t <= T_MIN) || (T_MAX <= t))
		t = (-coef[1] + sqrt(disc)) / (2.0 * coef[0]);
	if ((t <= T_MIN) || (T_MAX <= t))
		return (T_ERR);
	tmp = cast_ray(ray, t);
	tmp = vect_sub(&tmp, &cy->center);
	disc = vect_dot(&tmp, &cy->direction);
	if ((disc >= cy->height) || (disc < 0))
		return (T_ERR);
	
	return (t);
}