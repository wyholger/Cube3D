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

float	get_delta_x(t_data *data, int stepX)
{
	float	delta_x;

	delta_x = (sqrtf((float)data->imgs.sprite_mini.x_sz) + sqrtf(tanf(data->player.direction))) * (float)stepX;
	return (delta_x);
}

float	get_delta_y(t_data *data, int stepY)
{
	float	delta_y;

	delta_y = ((float)data->imgs.sprite_mini.x_sz * sinf(data->player.direction)) * (float)stepY;
	return (delta_y);
}

void	draw_ray(t_data *data)
{
	int stepX;
	int stepY;
//	int side_dist_X;
//	int side_dist_Y;

	float	delta_x;
	float 	delta_y;

	float	sin_dir;
	float	cos_dir;


	sin_dir = sinf(data->player.direction);
	cos_dir = cosf(data->player.direction);


//	float	c_x;
//	float 	c_y;

	data->player.direction = M_PI / 6 ;
	stepX = step_init_x(data);
	stepY = step_init_y(data);

	delta_x = (float)data->imgs.sprite_mini.x_sz / cos_dir;
//	delta_x = get_delta_x(data, stepX);
////	delta_y = get_delta_y(data, stepY);
	delta_y = data->player.y;
	delta_x += data->player.x;
	delta_y += ((float)data->imgs.sprite_mini.x_sz * (float)stepY);
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win,(int)delta_x, (int)delta_y, 0x11cc03);
	printf("step x = %d; y = %d\ndir = %f\npos x = %f; y = %f\npos delta_x = %f; y = %f\n", stepX, stepY, data->player.direction, data->player.x, data->player.y, delta_x, delta_y);

}