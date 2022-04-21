#include "../../include/cube3d.h"

int step_init_y(t_data *data)
{
	if (data->player.direction > M_PI && data->player.direction < M_PI * 2)
		return (1);
	return (-1);
}

int step_init_x(t_data *data)
{
	if (data->player.direction > 0 && data->player.direction < M_PI / 2)
		return (1);
	if (data->player.direction > ((3 * M_PI) / 2) && data->player.direction < M_PI * 2)
		return (1);
	return (-1);
}

void	draw_ray(t_data *data)
{
	int stepX;
	int stepY;
//	int side_dist_X;
//	int side_dist_Y;

	data->player.direction = M_PI / 3;
	stepX = step_init_x(data);
	stepY = step_init_y(data);
	printf("step x = %d; y = %d\n dir = %f\n", stepX, stepY, data->player.direction);

}