#include <miniRT.h>

void	calc_ray_hit(t_world *world)
{
	t_list	*lst;
	t_objs	*obj;
	double	t;
	double	min_so_far;

	lst = world->objs;
	min_so_far = T_ERR;
	while (lst != NULL)
	{
		obj = lst->content;
		if (obj->id == PLANE)
			t = hit_plane(&world->ray, obj);
		else if (obj->id == SPHERE)
			t = hit_sphere(&world->ray, obj);
		else if (obj->id == CYLINDER)
			t = hit_cylinder(&world->ray, obj);
		if ((t >= 0) && ((t <= min_so_far) && (t < T_MAX)))
		{
			world->hit.obj = obj;
			min_so_far = t;
		}	
		lst = lst->next;
	}
	if (min_so_far < T_MAX)
		calc_nearest(world, world->hit.obj, min_so_far);
}