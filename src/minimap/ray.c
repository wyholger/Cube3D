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

//void	init_final_hypotenuse(t_data *data, t_ray *ray)
//{
//	ray->len = sqrtf(powf(ray->delta_x - data->player.x, 2) + powf(ray->delta_y - data->player.y, 2));
//}

void	ray_computing_cycle(t_data *data, t_ray *ray)
{
	int 	flag_wall;

	flag_wall = init_ray_vars(data, ray);
	while(flag_wall == 0)
	{
		ray->hypotenuse_vertical = get_hypotenuse_to_vertical(data, ray->cos_dir, ray);
		ray->hypotenuse_horizontal = get_hypotenuse_to_horizontal(data, ray->sin_dir, ray);
		if (fabsf(ray->hypotenuse_vertical) < fabsf(ray->hypotenuse_horizontal))
		{
			flag_wall = get_flag_wall_to_horizontal(data, ray);
			if (flag_wall == 0)
				ray->len = sqrtf(powf(ray->delta_x - data->player.x, 2) + powf(ray->delta_y - data->player.y, 2));
//				ray->len = fabsf(ray->hypotenuse_vertical);
		}
		else
		{
			flag_wall = get_flag_wall_to_vertical(data, ray);
			if (flag_wall == 0)
				ray->len = sqrtf(powf(ray->delta_x - data->player.x, 2) + powf(ray->delta_y - data->player.y, 2));
//				ray->len = fabsf(ray->hypotenuse_horizontal);
		}
//		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) data->ray.delta_x, (int) data->ray.delta_y, 0x11cc03);
	}
	draw_line(data, ray);
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
	x = (int)(ray->delta_x / data->imgs.sprite_mini.x_sz) ;
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
		flag_wall = 1;
	}
	return (flag_wall);
}

int check_wall_vertical(t_data *data, t_ray *ray, int dep)
{
	int 	flag_wall;
	int 	x;
	int 	y;

	flag_wall = 0;
	ray->delta_x = data->player.x + ((data->player.offset_x + (data->imgs.sprite_mini.x_sz * dep)) * (float)ray->stepX);
	ray->delta_y = sqrtf((powf(ray->hypotenuse_vertical, 2) - powf((fabsf(data->player.x) - fabsf(ray->delta_x)), 2)));
	ray->delta_y = data->player.y + (ray->delta_y * ray->stepY);
//	if (ray->flag_first == 1)
//		printf("x = %f; y = %f; d_x = %f; d_y = %f; vert\n", data->player.x, data->player.y, ray->delta_x, ray->delta_y);
	y = (int)(ray->delta_y / data->imgs.sprite_mini.x_sz);
	if (ray->stepX == -1)
		x = ((int)((ray->delta_x / data->imgs.sprite_mini.x_sz))) + ray->stepX;
	else
		x = ((int)((ray->delta_x / data->imgs.sprite_mini.x_sz)));

//	x = ((int)(ceilf(ray->delta_x / data->imgs.sprite_mini.x_sz))) + ray->stepX;

//	x = ((int)(ceilf(ray->delta_x / data->imgs.sprite_mini.x_sz))) + (ray->stepX * -1);
//	if (ray->flag_first == 1)
//		printf("X = %d, Y = %d\n", x, y);
	if (data->ch_map[y][x] == '1')
	{
		init_wall_direction_for_vertical(ray);
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
//	if (ray->flag_first == 1)
	draw_line(data, ray);
//	pause();
}