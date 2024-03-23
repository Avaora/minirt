#include <miniRT.h>

void	calc_shadow_ray(t_world *world)
{
	t_list	*lst;
	t_objs	*obj;
	double	min_so_far;
	double	t;

	lst = world->objs;
	min_so_far = T_MAX;
	world->hit.is_hit = 0;
	while (lst != NULL)
	{
		obj = lst->content;
		if (obj->id == PLANE)
			t = hit_plane(&world->ray, obj);
		else if (obj->id == SPHERE)
			t = hit_sphere(&world->ray, obj);
		else if (obj->id == CYLINDER)
			t = hit_cylinder(&world->ray, obj);
		if ((t >= 0) && (t <= min_so_far) && (t < T_MAX))
			min_so_far = t;
		lst = lst->next;
	}
	calc_shadow(world, min_so_far);
}