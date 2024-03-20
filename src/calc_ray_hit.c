#include <miniRT.h>

void	calc_ray_hit(t_world *world)
{
	t_list	*lst;
	t_objs	*obj;

	lst = world->objs;
	set_hit_struct(world);
	while (lst != NULL)
	{
		obj = lst->content;
		if (obj->id == PLANE)
			hit_plane(world, obj);
		else if (obj->id == SPHERE)
			hit_sphere(world, obj);
		else if (obj->id == CYLINDER)
			hit_cylinder(world, obj);
		lst = lst->next;
	}
}