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

float	get_hypotenuse_to_vertical(t_data *data, float cos_dir, int flag_first)
{
	float	hypotenuse;

	if (flag_first == 0)
		if (data->ray.stepX == 1)
		{
			printf("+++ cos\n");
			hypotenuse = (data->ray.offset_x / cos_dir);
		}
		else
		{
			printf("--- cos\n");
			hypotenuse = (data->ray.offset_x / (cos_dir * -1));
		}
	else
	{
		if (data->ray.stepX == 1)
		{
			printf("+++ cos\n");
			hypotenuse = (data->player.offset_x / cos_dir);
		}
		else
		{
			printf("--- cos\n");
			hypotenuse = (data->player.offset_x / (cos_dir * -1));
		}
		printf("vert offset = %f; hipotinuse = %f\n", data->player.offset_x, hypotenuse);
	}
	return (hypotenuse);
}

float	get_hypotenuse_to_horizontal(t_data *data, float sin_dir, int flag_first)
{
	float	hypotenuse;

	if (flag_first == 0)
	{
		if (data->ray.stepY == 1)
		{
//			printf("+++ sin\n");
			hypotenuse = (data->ray.offset_y / sin_dir);
		}
		else
		{
//			printf("--- sin\n");
			hypotenuse = (data->ray.offset_y / (sin_dir * -1));
		}
//		printf("horis offset = %f; hipotinuse = %f\n", data->player.offset_y, hypotenuse);
	}
	else
	{
		if (data->ray.stepY == 1)
		{
			printf("+++ sin\n");
			hypotenuse = (data->player.offset_y / sin_dir);
		}
		else
		{
			printf("--- sin\n");
			hypotenuse = (data->player.offset_y / (sin_dir * -1));
		}
		printf("horis offset = %f; hipotinuse = %f\n", data->player.offset_y, hypotenuse);
	}
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
	printf("Ofset x = %f; y = %f; stepX = %d; stepY = %d; dir = %f\n", data->player.offset_x, data->player.offset_y, data->ray.stepX, data->ray.stepY, data->player.direction);
}

//void	check_wall(t_data *data)
//{
//
//}

void	init_offset_for_ray(t_data *data, float prev_delta_x, float prev_delta_y)
{
	data->ray.offset_x = fmodf(prev_delta_x, (int)data->imgs.sprite_mini.x_sz);
	if (data->ray.stepX == 1)
		data->ray.offset_x = data->imgs.sprite_mini.x_sz - data->ray.offset_x;
	data->ray.offset_y = fmodf(prev_delta_y, (int)data->imgs.sprite_mini.x_sz);
	if (data->ray.stepY == 1)
		data->ray.offset_y = data->imgs.sprite_mini.x_sz - data->ray.offset_y;
	printf("Ofset for ray x = %f; y = %f; stepX = %d; stepY = %d; dir = %f\n", data->ray.offset_x, data->ray.offset_y, data->ray.stepX, data->ray.stepY, data->player.direction);
}

void	draw_ray_continuance(t_data *data, float prev_delta_x, float prev_delta_y)
{
	float	hypotenuse_vertical;
	float	hypotenuse_horizontal;
	float 	result;
	float	delta_x;
	float 	delta_y;
	int 	flag_wall;

	flag_wall = 0;
	while (flag_wall == 0)
	{
		init_offset_for_ray(data, prev_delta_x, prev_delta_y);
		hypotenuse_vertical = get_hypotenuse_to_vertical(data, data->ray.cos_dir, 0);
		hypotenuse_horizontal = get_hypotenuse_to_horizontal(data, data->ray.sin_dir, 0);
		if (fabsf(hypotenuse_vertical) < fabsf(hypotenuse_horizontal))
		{
			result = powf(hypotenuse_vertical, 2) - powf((float)data->imgs.sprite_mini.x_sz, 2);
			delta_y = sqrtf(result);
			delta_y *= (float) data->ray.stepY;
			delta_y += prev_delta_y;
			delta_x = prev_delta_x + ((float)data->imgs.sprite_mini.x_sz * (float) data->ray.stepX);
//			if (data->ch_map[(int)(delta_y / (float)data->imgs.sprite_mini.x_sz)][(int)(delta_x / (float)data->imgs.sprite_mini.x_sz) + data->ray.stepX] == '1')
//			{
//				flag_wall = 1;
//				printf("WAAAAAAAAAAALLL\n");
//			}
		}
		else
		{
			result = powf(hypotenuse_horizontal, 2) - powf((float)data->imgs.sprite_mini.x_sz, 2);
			delta_x = sqrtf(result);
			delta_x *= (float) data->ray.stepX;
			delta_x += prev_delta_x;
			delta_y = prev_delta_y + ((float)data->imgs.sprite_mini.x_sz * (float) data->ray.stepY);
//			if (data->ch_map[(int)(delta_y / (float)data->imgs.sprite_mini.x_sz) + data->ray.stepY][(int)(delta_x / (float)data->imgs.sprite_mini.x_sz)] == '1')
//			{
//				flag_wall = 1;
//				printf("WAAAAAAAAAAALLL\n");
//			}

		}
		flag_wall = 1;
		mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) delta_x, (int) delta_y, 0x11cc03);
		prev_delta_x = delta_x;
		prev_delta_y = delta_y;
	}
}

void	draw_ray(t_data *data)
{
	float	prev_delta_x;
	float	prev_delta_y;
	float	delta_x;
	float 	delta_y;
	float	hypotenuse_vertical;
	float	hypotenuse_horizontal;
	float 	result;
	int 	flag_wall;

	prev_delta_x = data->player.x;
	prev_delta_y = data->player.y;
	flag_wall = 0;
	data->ray.sin_dir = sinf(data->player.direction);
	data->ray.cos_dir = cosf(data->player.direction);
	data->ray.stepX = step_init_x(data);
	data->ray.stepY = step_init_y(data);
	init_offset(data);
	hypotenuse_vertical = get_hypotenuse_to_vertical(data, data->ray.cos_dir, 1);
	hypotenuse_horizontal = get_hypotenuse_to_horizontal(data, data->ray.sin_dir, 1);
	printf("player before x = %d; y = %d\n", data->player.x_i, data->player.y_i);
	if (fabsf(hypotenuse_vertical) < fabsf(hypotenuse_horizontal))
	{
		result = powf(hypotenuse_vertical, 2) - powf(data->player.offset_x, 2);
		delta_y = sqrtf(result);
		delta_y *= (float) data->ray.stepY;
		delta_y += prev_delta_y;
		delta_x = prev_delta_x + (data->player.offset_x * (float) data->ray.stepX);
//		data->player.x_i += data->ray.stepX;
		printf("%c\n", data->ch_map[data->player.y_i][data->player.x_i]);
		if (data->ch_map[data->player.y_i][data->player.x_i + data->ray.stepX] == '1')
		{
			flag_wall = 1;
			printf("WAAAAAAAAAAALLL\n");
		}
		printf("AAA\n");
	}
	else
	{
		result = powf(hypotenuse_horizontal, 2) - powf(data->player.offset_y, 2);
		delta_x = sqrtf(result);
		delta_x *= (float) data->ray.stepX;
		delta_x += prev_delta_x;
		delta_y = prev_delta_y + (data->player.offset_y * (float) data->ray.stepY);
		printf("%c\n", data->ch_map[data->player.y_i][data->player.x_i]);
		if (data->ch_map[data->player.y_i + data->ray.stepY][data->player.x_i] == '1')
		{
			flag_wall = 1;
			printf("WAAAAAAAAAAALLL\n");
		}
		printf("BBB\n");
	}
	printf("player after x = %d; y = %d\n", data->player.x_i, data->player.y_i);
	mlx_pixel_put(data->mlx.mlx, data->mlx.mlx_win, (int) delta_x, (int) delta_y, 0x11cc03);
	printf("step x = %d; y = %d\ndir = %f\npos x = %f; y = %f\npos delta_x = %f; y = %f\n", data->ray.stepX,
		   data->ray.stepY, data->player.direction, data->player.x, data->player.y, delta_x, delta_y);
	draw_ray_continuance(data, delta_x, delta_y);
//	prev_delta_x = delta_x;
//	prev_delta_y = delta_y;
//	hypotenuse_vertical = get_hypotenuse_to_vertical(data, cos_dir, 0);
//	hypotenuse_horizontal = get_hypotenuse_to_horizontal(data, sin_dir, 0);
}