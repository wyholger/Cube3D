/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:55:26 by wyholger          #+#    #+#             */
/*   Updated: 2022/04/29 22:27:01 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_wall_horizontal(t_data *data, t_ray *ray, int dep)
{
	int	flag_wall;

	flag_wall = 0;
	ray->delta_y = data->player.y + ((data->player.offset_y + \
	(data->imgs.sprite_mini.x_sz * dep)) * (float)ray->step_y);
	ray->delta_x = sqrtf((powf(ray->hypotenuse_horizontal, 2) - \
	powf((fabsf(data->player.y) - fabsf(ray->delta_y)), 2)));
	ray->delta_x = data->player.x + (ray->delta_x * ray->step_x);
	ray->x = (int)(ray->delta_x / data->imgs.sprite_mini.x_sz);
	if (ray->step_y == -1)
		ray->y = ((int)((ray->delta_y / data->imgs.sprite_mini.x_sz))) + \
		ray->step_y;
	else
		ray->y = ((int)((ray->delta_y / data->imgs.sprite_mini.x_sz)));
	if (data->ch_map[ray->y][ray->x] == '1')
	{
		init_wall_direction_for_horizontal(ray);
		init_left_sprite_dist(data, ray);
		flag_wall = 1;
	}
	return (flag_wall);
}

int	check_wall_vertical(t_data *data, t_ray *ray, int dep)
{
	int	flag_wall;

	flag_wall = 0;
	ray->delta_x = data->player.x + ((data->player.offset_x + \
	(data->imgs.sprite_mini.x_sz * dep)) * (float)ray->step_x);
	ray->delta_y = sqrtf((powf(ray->hypotenuse_vertical, 2) - \
	powf((fabsf(data->player.x) - fabsf(ray->delta_x)), 2)));
	ray->delta_y = data->player.y + (ray->delta_y * ray->step_y);
	ray->y = (int)(ray->delta_y / data->imgs.sprite_mini.x_sz);
	if (ray->step_x == -1)
		ray->x = ((int)((ray->delta_x / data->imgs.sprite_mini.x_sz))) + \
		ray->step_x;
	else
		ray->x = ((int)((ray->delta_x / data->imgs.sprite_mini.x_sz)));
	if (data->ch_map[ray->y][ray->x] == '1')
	{
		init_wall_direction_for_vertical(ray);
		init_left_sprite_dist(data, ray);
		flag_wall = 1;
	}
	return (flag_wall);
}

float	get_hypotenuse_to_vertical_2(t_data *data, \
	float cos_dir, t_ray *ray, int dep)
{
	float	hypotenuse;

	if (ray->step_x == 1)
		hypotenuse = ((data->player.offset_x + \
		(float)(data->imgs.sprite_mini.x_sz * dep)) / cos_dir);
	else
		hypotenuse = ((data->player.offset_x + \
		(float)(data->imgs.sprite_mini.x_sz * dep)) / (cos_dir * -1));
	hypotenuse = fabsf(hypotenuse);
	return (hypotenuse);
}

float	get_hypotenuse_to_horizontal_2(t_data *data, \
	float sin_dir, t_ray *ray, int dep)
{
	float	hypotenuse;

	if (ray->step_y == 1)
		hypotenuse = ((data->player.offset_y + \
		(float)(data->imgs.sprite_mini.x_sz * dep)) / sin_dir);
	else
		hypotenuse = ((data->player.offset_y + \
		(float)(data->imgs.sprite_mini.x_sz * dep)) / (sin_dir * -1));
	hypotenuse = fabsf(hypotenuse);
	return (hypotenuse);
}

void	ray_computing_cycle(t_data *data, t_ray *ray)
{
	int		flag_wall;
	int		dep_horys;
	int		dep_vert;

	dep_horys = 0;
	dep_vert = 0;
	flag_wall = init_ray_vars(data, ray);
	while (flag_wall == 0)
	{
		ray->hypotenuse_vertical = fabsf(get_hypotenuse_to_vertical_2(data, \
		ray->cos_dir, ray, dep_vert));
		ray->hypotenuse_horizontal = fabsf(get_hypotenuse_to_horizontal_2(data, \
		ray->sin_dir, ray, dep_horys));
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
	}
	init_final_hypotenuse(data, ray);
}
