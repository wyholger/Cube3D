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

void	init_wall_direction_for_vertical(t_ray *ray)
{
	if (ray->stepX == -1)
		ray->wall_direction = 'E';
	else
		ray->wall_direction = 'W';
}

void	init_wall_direction_for_horizontal(t_ray *ray)
{
	if (ray->stepY == -1)
		ray->wall_direction = 'N';
	else
		ray->wall_direction = 'S';
}

int check_wall_horizontal(t_data *data, t_ray *ray, int dep)
{
	int 	flag_wall;
	int 	x;
	int 	y;

	flag_wall = 0;
	ray->delta_y = data->player.y + ((data->player.offset_y + (data->imgs.sprite_mini.x_sz * dep)) * (float)ray->stepY);
	ray->delta_x = sqrtf((powf(ray->hypotenuse_horizontal, 2) - powf((fabsf(data->player.y) - fabsf(ray->delta_y)), 2)));
	ray->delta_x = data->player.x + (ray->delta_x * ray->stepX);
//	if (ray->flag_first == 1)
//		printf("x = %f; y = %f; d_x = %f; d_y = %f; horis\n", data->player.x, data->player.y, ray->delta_x, ray->delta_y);
	x = (int)(ray->delta_x / data->imgs.sprite_mini.x_sz);
	if (ray->stepY == -1)
		y = ((int)((ray->delta_y / data->imgs.sprite_mini.x_sz))) + ray->stepY;
	else
		y = ((int)((ray->delta_y / data->imgs.sprite_mini.x_sz)));

//	y = ((int)(ceilf(ray->delta_y / data->imgs.sprite_mini.x_sz))) + ray->stepY;

//	y = ((int)(ceilf(ray->delta_y / data->imgs.sprite_mini.x_sz))) + (ray->stepY * -1);
//	if (ray->flag_first == 1)
//		printf("X = %d, Y = %d\n", x, y);
	if (data->ch_map[y][x] == '1')
	{
		init_wall_direction_for_horizontal(ray);
		if (ray->flag_first == 1)
			printf("X = %d, Y = %d;\n", x, y);
		init_left_sprite_dist(data, ray);
		flag_wall = 1;
	}
	return (flag_wall);
}

int check_wall_vertical(t_data *data, t_ray *ray, int dep)
{
	int 	flag_wall;

	flag_wall = 0;
	ray->delta_x = data->player.x + ((data->player.offset_x + (data->imgs.sprite_mini.x_sz * dep)) * (float)ray->stepX);
	ray->delta_y = sqrtf((powf(ray->hypotenuse_vertical, 2) - powf((fabsf(data->player.x) - fabsf(ray->delta_x)), 2)));
	ray->delta_y = data->player.y + (ray->delta_y * ray->stepY);
//	if (ray->flag_first == 1)
//		printf("x = %f; y = %f; d_x = %f; d_y = %f; vert\n", data->player.x, data->player.y, ray->delta_x, ray->delta_y);
	ray->y = (int)(ray->delta_y / data->imgs.sprite_mini.x_sz);
	if (ray->stepX == -1)
		ray->x = ((int)((ray->delta_x / data->imgs.sprite_mini.x_sz))) + ray->stepX;
	else
		ray->x = ((int)((ray->delta_x / data->imgs.sprite_mini.x_sz)));

//	x = ((int)(ceilf(ray->delta_x / data->imgs.sprite_mini.x_sz))) + ray->stepX;

//	x = ((int)(ceilf(ray->delta_x / data->imgs.sprite_mini.x_sz))) + (ray->stepX * -1);
//	if (ray->flag_first == 1)
//		printf("X = %d, Y = %d\n", x, y);
	if (data->ch_map[ray->y][ray->x] == '1')
	{
		init_wall_direction_for_vertical(ray);
		init_left_sprite_dist(data, ray);
		flag_wall = 1;
	}
	return (flag_wall);
}

float	get_hypotenuse_to_vertical_2(t_data *data, float cos_dir, t_ray *ray, int dep)
{
	float	hypotenuse;

	if (ray->stepX == 1)
		hypotenuse = ((data->player.offset_x + (float)(data->imgs.sprite_mini.x_sz * dep)) / cos_dir);
	else
		hypotenuse = ((data->player.offset_x + (float)(data->imgs.sprite_mini.x_sz * dep)) / (cos_dir * -1));//проверить надобность умножения на -1
	hypotenuse = fabsf(hypotenuse);
	return (hypotenuse);
}

float	get_hypotenuse_to_horizontal_2(t_data *data, float sin_dir, t_ray *ray, int dep)
{
	float	hypotenuse;

	if (ray->stepY == 1)
		hypotenuse = ((data->player.offset_y + (float)(data->imgs.sprite_mini.x_sz * dep)) / sin_dir);
	else
		hypotenuse = ((data->player.offset_y  + (float)(data->imgs.sprite_mini.x_sz * dep)) / (sin_dir * -1));//проверить надобность умножения на -1
	hypotenuse =  fabsf(hypotenuse);
	return (hypotenuse);
}

void	init_final_hypotenuse(t_data *data, t_ray *ray)
{
	ray->len = sqrtf(powf(ray->delta_x - data->player.x, 2) + powf(ray->delta_y - data->player.y, 2));
}


void	ray_computing_cycle_2(t_data *data, t_ray *ray)
{
	int 	flag_wall;
	int 	dep_horys;
	int 	dep_vert;
//	ray->direction += 0.35;
//	data->player.x = 99.500000;
//	data->player.y = 87.000000;

	dep_horys = 0;
	dep_vert = 0;
	flag_wall = init_ray_vars(data, ray);
//	if (ray->flag_first == 1)
//		printf("----------------------------------------\n");
	while(flag_wall == 0)
	{
		ray->hypotenuse_vertical = fabsf(get_hypotenuse_to_vertical_2(data, ray->cos_dir, ray, dep_vert));
		ray->hypotenuse_horizontal = fabsf(get_hypotenuse_to_horizontal_2(data, ray->sin_dir, ray, dep_horys));
//		if (ray->flag_first == 1)
//			printf("Hyp vert = %f; hyp gor = %f; stepX = %d; stepY = %d\n", ray->hypotenuse_vertical, ray->hypotenuse_horizontal, ray->stepX, ray->stepY);
		if (fabsf(ray->hypotenuse_vertical) < fabsf(ray->hypotenuse_horizontal))
		{
			flag_wall = check_wall_vertical(data, ray, dep_vert);
			dep_vert++;
		}
		else
		{
			flag_wall = check_wall_horizontal(data, ray, dep_horys);
			dep_horys++;
		}
		if (ray->flag_first == 1)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) ray->delta_x, (int) ray->delta_y, 0x991103);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, ((int) ray->delta_x) + 1, (int) ray->delta_y, 0x991103);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) ray->delta_x, ((int) ray->delta_y) + 1, 0x991103);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) ray->delta_x, ((int) ray->delta_y) - 1, 0x991103);
			mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, ((int) ray->delta_x) - 1, (int) ray->delta_y, 0x991103);

		}
	}
	init_final_hypotenuse(data, ray);
	if (ray->flag_first == 0)
		draw_line(data, ray, 0xF9FE72);
	else
		draw_line(data, ray, 0xFF0000);

//	pause();
}