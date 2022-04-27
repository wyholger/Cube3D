#include "../../include/cube3d.h"

void	check_to_open_img(t_data *data, void *img)
{
	if (!img)
		exit_after_validate(data, 8);
}

void	clean_wall(t_img *wall)
{
	char *dst;
	int x;
	int y;

	y = 0;
	while (y++ < wall->y_sz - 1)
	{
		x = 0;
		while (x++ < wall->x_sz - 1)
		{
			dst = wall->adr + (y * (wall->x_sz * 4) + x * 4);
			*(unsigned int *)dst = 0xFF999999;
		}
	}
}