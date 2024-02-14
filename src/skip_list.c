#include <minirt.h>

size_t	skip_list(const char *str, const char *list)
{
	size_t	i;
	size_t	x;

	i = 0;
	while (str[i] != 0x0)
	{
		x = 0;
		while ((list[x] != 0x0) && (str[i] != list[x]))
			x++;
		if (list[x] == 0x0)
			break;
		i++;
	}
	if (i == ft_strlen(str))
		return (-1);
	return (i);
}