#include "../../include/cube3d.h"

int	init_ray_vars(t_data *data, t_ray *ray)
{
	ray->sin_dir = sinf(ray->direction);
	ray->cos_dir = cosf(ray->direction);
	ray->stepX = step_init_x(ray);
	ray->stepY = step_init_y(ray);
	init_offset(data, ray);
	return (0);
}

int get_flag_wall_to_vertical(t_data *data, t_ray *ray)
{
	int 	offset_for_wall_check_in_ch_map;
	int 	flag_wall;

	flag_wall = 0;
	ray->delta_x = sqrtf((powf(ray->hypotenuse_horizontal, 2) - powf(data->player.offset_y, 2)));
	ray->delta_x *= (float) ray->stepX;
	ray->delta_x += data->player.x;
	ray->delta_y = data->player.y + (data->player.offset_y * (float) ray->stepY);
	data->player.offset_y += data->imgs.sprite_mini.x_sz;
	if (ray->stepY == 1)
		offset_for_wall_check_in_ch_map = 0;
	else
		offset_for_wall_check_in_ch_map = ray->stepY;
	if (data->ch_map[(int)(ray->delta_y / data->imgs.sprite_mini.x_sz) + offset_for_wall_check_in_ch_map][(int)(ray->delta_x / data->imgs.sprite_mini.x_sz) ] == '1')
		flag_wall = 1;
	return (flag_wall);
}

int get_flag_wall_to_horizontal(t_data *data, t_ray *ray)
{
	int 	offset_for_wall_check_in_ch_map;
	int 	flag_wall;

	flag_wall = 0;
	ray->delta_y = sqrtf((powf(ray->hypotenuse_vertical, 2) - powf(data->player.offset_x, 2)));
	ray->delta_y *= (float) ray->stepY;
	ray->delta_y += data->player.y;
	ray->delta_x = data->player.x + (data->player.offset_x * (float) ray->stepX);
	data->player.offset_x += data->imgs.sprite_mini.x_sz;
	if (ray->stepX == 1)
		offset_for_wall_check_in_ch_map = 0;
	else
		offset_for_wall_check_in_ch_map = ray->stepX;
	if (data->ch_map[(int)(ray->delta_y / data->imgs.sprite_mini.x_sz)][(int)(ray->delta_x / data->imgs.sprite_mini.x_sz) + offset_for_wall_check_in_ch_map] == '1')
		flag_wall = 1;
	return (flag_wall);
}

void	ray_computing_cycle(t_data *data, t_ray *ray)
{
	int 	flag_wall;

	flag_wall = init_ray_vars(data, ray);
	while(flag_wall == 0)
	{
		ray->hypotenuse_vertical = get_hypotenuse_to_vertical(data, ray->cos_dir, ray);
		ray->hypotenuse_horizontal = get_hypotenuse_to_horizontal(data, ray->sin_dir, ray);
		if (fabsf(ray->hypotenuse_vertical) < fabsf(ray->hypotenuse_horizontal))
			flag_wall = get_flag_wall_to_horizontal(data, ray);
		else
			flag_wall = get_flag_wall_to_vertical(data, ray);
//		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) data->ray.delta_x, (int) data->ray.delta_y, 0x11cc03);
	}
	draw_line(data, ray);
}