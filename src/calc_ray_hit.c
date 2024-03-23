#include <miniRT.h>

void	calc_ray_hit(t_world *world)
{
	t_list	*lst;
	t_objs	*obj;
	double	t;

	lst = world->objs;
	set_hit_struct(world);
	while (lst != NULL)
	{
		obj = lst->content;
		if (obj->id == PLANE)
			t = hit_plane(&world->ray, obj);
		else if (obj->id == SPHERE)
			t = hit_sphere(&world->ray, obj);
		else if (obj->id == CYLINDER)
			t = hit_cylinder(&world->ray, obj);
		if ((t >= 0) && ((t <= world->hit.t) && (t < T_MAX)))
			calc_nearest(world, obj, t);
		lst = lst->next;
	}
}