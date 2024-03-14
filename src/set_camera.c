#include <miniRT.h>

void	set_camera(t_world *world, t_scene const *scene)
{
	world->camera.center.x = scene->coord[0];
	world->camera.center.y = scene->coord[1];
	world->camera.center.z = scene->coord[2];
	world->camera.direction.x = scene->vector[0];
	world->camera.direction.y = scene->vector[1];
	world->camera.direction.z = scene->vector[2];
	world->camera.field_of_view = scene->fov;
}