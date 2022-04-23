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

float	get_hypotenuse_to_vertical(t_data *data, float cos_dir)
{
	float	hypotenuse;

	if (data->ray.stepX == 1)
		hypotenuse = (data->player.offset_x / cos_dir);
	else
		hypotenuse = (data->player.offset_x / (cos_dir * -1));
	return (hypotenuse);
}

float	get_hypotenuse_to_horizontal(t_data *data, float sin_dir)
{
	float	hypotenuse;

	if (data->ray.stepY == 1)
		hypotenuse = (data->player.offset_y / sin_dir);
	else
		hypotenuse = (data->player.offset_y / (sin_dir * -1));
	return (hypotenuse);
}

void	init_offset(t_data *data)
{
	data->player.offset_x = fmodf(data->player.x, (int)data->imgs.sprite_mini.x_sz);
	if (data->ray.stepX == 1)
		data->player.offset_x = data->imgs.sprite_mini.x_sz - data->player.offset_x;
	data->player.offset_y = fmodf(data->player.y, (int)data->imgs.sprite_mini.x_sz);
	if (data->ray.stepY == 1)
		data->player.offset_y = data->imgs.sprite_mini.x_sz - data->player.offset_y;
}
