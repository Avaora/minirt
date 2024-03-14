#include <miniRT.h>

void	set_ambient(t_world *world, t_scene const *scene)
{
	world->amb_light.power = scene->amb_light;
	world->amb_light.color.r = scene->rgb[0];
	world->amb_light.color.g = scene->rgb[1];
	world->amb_light.color.b = scene->rgb[2];
}