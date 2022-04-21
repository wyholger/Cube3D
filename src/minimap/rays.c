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

	float	delta_x;
	float 	delta_y;
//	float	c_x;
//	float 	c_y;

	data->player.direction = M_PI / 3;
	delta_x = (float)data->imgs.sprite_mini.x_sz / tanf(data->player.direction);
	delta_y = data->player.y + (float)data->imgs.sprite_mini.x_sz;
	stepX = step_init_x(data);
	stepY = step_init_y(data);
	printf("step x = %d; y = %d\ndir = %f\npos x = %f; y = %f\npos delta_x = %f; y = %f\n", stepX, stepY, data->player.direction, data->player.x, data->player.y, delta_x, delta_y);

}