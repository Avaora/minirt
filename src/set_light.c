#include <miniRT.h>

void	set_light(t_world *world, t_scene const *scene)
{
	world->light.center.x = scene->coord[0];
	world->light.center.y = scene->coord[1];
	world->light.center.z = scene->coord[2];
	world->light.power = scene->brightness;
	world->light.color.r = scene->rgb[0];
	world->light.color.g = scene->rgb[1];
	world->light.color.b = scene->rgb[2];
}