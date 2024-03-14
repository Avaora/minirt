#include <miniRT.h>

void	set_obj_plane(t_world *world, t_scene const *scene)
{
	t_plane	*obj;
	t_list	*node;

	obj = zalloc(sizeof(*obj));
	if (obj == NULL)
		set_err(NULL);
	obj->center.x = scene->coord[0];
	obj->center.y = scene->coord[1];
	obj->center.z = scene->coord[2];
	obj->direction.x = scene->vector[0];
	obj->direction.y = scene->vector[1];
	obj->direction.z = scene->vector[2];
	obj->color.r = scene->rgb[0];
	obj->color.g = scene->rgb[1];
	obj->color.b = scene->rgb[2];
	node = ft_lstnew(obj);
	if (node == NULL)
		set_err(NULL);
	ft_lstadd_back(&world->objs, node);
}