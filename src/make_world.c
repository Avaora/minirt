#include <minirt.h>

void	make_world(t_world *world, t_list const *scene)
{
	set_objects(world, scene);
	set_screen(world);
}