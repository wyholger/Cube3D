#include "../../include/cube3d.h"

int	init_ray_vars(t_data *data)
{
	data->ray.sin_dir = sinf(data->player.direction);
	data->ray.cos_dir = cosf(data->player.direction);
	data->ray.stepX = step_init_x(data);
	data->ray.stepY = step_init_y(data);
	init_offset(data);
	return (0);
}

int get_flag_wall_to_vertical(t_data *data)
{
	int 	offset_for_wall_check_in_ch_map;
	int 	flag_wall;

	flag_wall = 0;
	data->ray.delta_x = sqrtf((powf(data->ray.hypotenuse_horizontal, 2) - powf(data->player.offset_y, 2)));
	data->ray.delta_x *= (float) data->ray.stepX;
	data->ray.delta_x += data->player.x;
	data->ray.delta_y = data->player.y + (data->player.offset_y * (float) data->ray.stepY);
	data->player.offset_y += data->imgs.sprite_mini.x_sz;
	if (data->ray.stepY == 1)
		offset_for_wall_check_in_ch_map = 0;
	else
		offset_for_wall_check_in_ch_map = data->ray.stepY;
	if (data->ch_map[(int)(data->ray.delta_y / data->imgs.sprite_mini.x_sz) + offset_for_wall_check_in_ch_map][(int)(data->ray.delta_x / data->imgs.sprite_mini.x_sz) ] == '1')
		flag_wall = 1;
	return (flag_wall);
}

int get_flag_wall_to_horizontal(t_data *data)
{
	int 	offset_for_wall_check_in_ch_map;
	int 	flag_wall;

	flag_wall = 0;
	data->ray.delta_y = sqrtf((powf(data->ray.hypotenuse_vertical, 2) - powf(data->player.offset_x, 2)));
	data->ray.delta_y *= (float) data->ray.stepY;
	data->ray.delta_y += data->player.y;
	data->ray.delta_x = data->player.x + (data->player.offset_x * (float) data->ray.stepX);
	data->player.offset_x += data->imgs.sprite_mini.x_sz;
	if (data->ray.stepX == 1)
		offset_for_wall_check_in_ch_map = 0;
	else
		offset_for_wall_check_in_ch_map = data->ray.stepX;
	if (data->ch_map[(int)(data->ray.delta_y / data->imgs.sprite_mini.x_sz)][(int)(data->ray.delta_x / data->imgs.sprite_mini.x_sz) + offset_for_wall_check_in_ch_map] == '1')
		flag_wall = 1;
	return (flag_wall);
}

void	ray_computing_cycle(t_data *data)
{
	int 	flag_wall;

	flag_wall = init_ray_vars(data);
	while(flag_wall == 0)
	{
		data->ray.hypotenuse_vertical = get_hypotenuse_to_vertical(data, data->ray.cos_dir);
		data->ray.hypotenuse_horizontal = get_hypotenuse_to_horizontal(data, data->ray.sin_dir);
		if (fabsf(data->ray.hypotenuse_vertical) < fabsf(data->ray.hypotenuse_horizontal))
			flag_wall = get_flag_wall_to_horizontal(data);
		else
			flag_wall = get_flag_wall_to_vertical(data);
//		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) data->ray.delta_x, (int) data->ray.delta_y, 0x11cc03);
	}
	draw_line(data, &data->ray);
}