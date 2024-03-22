#include <miniRT.h>

void	calc_shadow_ray(t_world *world)
{
	t_list	*lst;
	t_objs	*obj;
	double	t;

	t = T_ERR;
	lst = world->objs;
	set_hit_struct(world);
	while (lst != NULL)
	{
		obj = lst->content;
		if (obj->id == PLANE)
			t = hit_plane(world, obj);
		else if (obj->id == SPHERE)
			t = hit_sphere(world, obj);
		else if (obj->id == CYLINDER)
			t = hit_cylinder(world, obj);
		if ((t >= 0) && (t <= world->hit.t) && (t < T_MAX))
			calc_shadow(world, t, obj);
		lst = lst->next;
	}
}